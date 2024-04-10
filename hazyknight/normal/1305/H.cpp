#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int n,m,q,first,pos,ans,head,tail;
int l[MAXN];
int r[MAXN];
int b[MAXN];
int Q[MAXN];
int fix[MAXN];

ll T;
ll suml[MAXN];
ll sumr[MAXN];
ll sumb[MAXN];

void init()
{
	for (int i = 1;i <= n;i++)
	{
		suml[i] = l[i];
		sumr[i] = r[i];
	}
	sort(suml + 1,suml + n + 1);
	sort(sumr + 1,sumr + n + 1);
	for (int i = 1;i <= n;i++)
	{
		suml[i] += suml[i - 1];
		sumr[i] += sumr[i - 1];
	}
	reverse(suml,suml + n + 1);
	reverse(sumr,sumr + n + 1);
	fix[m + 1] = 0;
	for (int i = 1;i <= m + 1;i++)
		if (~fix[i])
		{
			pos = i;
			first = fix[i];
			break;
		}
}

ll getval(ll *a,ll *b)
{
	head = 1;
	tail = 0;
	for (int i = m;i >= 0;i--)
	{
		while (head < tail && (b[Q[tail]] - b[Q[tail - 1]]) * (Q[tail] - i) >= (b[i] - b[Q[tail]]) * (Q[tail - 1] - Q[tail]))
			tail--;
		Q[++tail] = i;
	}
	ll res = 1e18;
	for (int i = 0;i <= n;i++)
	{
		while (head < tail && (ll)Q[head] * i + b[Q[head]] >= (ll)Q[head + 1] * i + b[Q[head + 1]])
			head++;
		res = min(res,a[i] + (ll)Q[head] * i + b[Q[head]]);
	}
	return res;
}

ll MaxFlow()
{
	sumb[0] = 0;
	for (int i = 1;i <= m;i++)
		sumb[i] = b[i];
	reverse(sumb + 1,sumb + m + 1);
	for (int i = 1;i <= m;i++)
		sumb[i] += sumb[i - 1];
	reverse(sumb,sumb + m + 1);
	if (getval(suml,sumb) < suml[0])
		return -1;
	return getval(sumr,sumb);
}

bool putMIN(int L)
{
	for (int i = 1;i <= L;i++)
	{
		if (~fix[i] && fix[i] != first)
			return 0;
		b[i] = first;
	}
	int MN = 0;
	for (int i = m + 1;i > L;i--)
	{
		if (~fix[i])
			MN = fix[i];
		b[i] = MN;
	}
	return 1;
}

ll fill(int L,ll TT)
{
	int nxt = m + 1;
	for (int i = m;i >= L;i--)
		if (~fix[i] || i == L)
		{
			if (nxt == i + 1)
			{
				nxt = i;
				continue;
			}
			int low = b[nxt],high = b[i],inc = min(TT / (nxt - i - 1),(ll)high - low),rem = 0;
			if (inc < high - low)
				rem = TT % (nxt - i - 1);
			for (int j = i + 1;j < nxt;j++)
				b[j] += inc + (j - i <= rem);
			TT -= (ll)inc * (nxt - i - 1) + rem;
			nxt = i;
		}
	return TT;
}

bool ok(int L,int V)
{
	if (!putMIN(L))
		return 0;
	ll TT = T;
	for (int i = 1;i <= m;i++)
		TT -= b[i];
	if (TT < 0)
		return 0;
	ll used = TT;
	TT = fill(L,TT);
	used -= TT;
	if (TT > 0 && L >= pos)
		return 0;
	if (!TT && b[1] < V)
		return 0;
	if (TT > 0)
	{
		ll MN = 1e18;
		int inc = -1;
		for (int i = 0;i <= n - b[1];i++)
		{
			if (b[1] + i < V)
				continue;
			if ((ll)i * (pos - 1) < TT)
				continue;
			ll dis = max(0ll,(ll)i * L - TT);
			if (dis < MN)
			{
				MN = dis;
				inc = i;
			}
		}
		if (used < MN)
			return 0;
		putMIN(L);
		fill(L,used - MN);
		TT += MN;
		int add = 0,len = 0,add2 = 0;
		for (int i = 1;i <= inc;i++)
		{
			if (TT - pos + 1 >= (ll)(inc - i) * L && TT - pos + 1 <= (ll)(inc - i) * (pos - 1))
			{
				add++;
				TT -= pos - 1;
				continue;
			}
			len = pos - 1 - ((ll)(inc - i) * L - (TT - pos + 1));
			TT -= len;
			add2 = TT / L;
			break;
		}
		for (int i = 1;i < pos;i++)
			b[i] += add + (i <= len) + (i <= L) * add2;
	}
	return MaxFlow() == T;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d%d",&l[i],&r[i]);
	scanf("%d",&q);
	memset(fix,-1,sizeof(fix));
	for (int p,s,i = 1;i <= q;i++)
	{
		scanf("%d%d",&p,&s);
		fix[p] = s;
	}
	scanf("%lld",&T);
	init();
	int low = 1,high = m;
	if (!ok(1,0))
	{
		puts("-1 -1");
		return 0;
	}
	while (low < high)
	{
		int mid = low + high + 1 >> 1;
		if (ok(mid,0))
			low = mid;
		else
			high = mid - 1;
	}
	ans = low;
	low = first,high = n;
	while (low < high)
	{
		int mid = low + high + 1 >> 1;
		if (ok(ans,mid))
			low = mid;
		else
			high = mid - 1;
	}
	printf("%d %d\n",ans,low);
	return 0;
}