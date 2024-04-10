#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int mod = 998244353;

ll pw2[MAXN];

struct Data
{
	int n,m;
	map<int,int> a[MAXN];
	
	int cnt[MAXN][2], cnt_bad = 0;
	int t[MAXN], tot = 0;
	
	inline int get_bad(int x){ return cnt[x][0] && cnt[x][1];}
	inline void update(int x,int y,int k)
	{
		cnt_bad -= get_bad(x);
		if(a[x].find(y) != a[x].end())
		{
			--cnt[x][a[x][y] ^ (y&1)];
			a[x].erase(y);
			if(--t[x] == 0) --tot;
		}
		if(k != -1)
		{
			++cnt[x][k ^ (y&1)];
			a[x][y] = k;
			if(++t[x] == 1) ++tot;
		}
		cnt_bad += get_bad(x);
	}
	inline ll calc(void){ return cnt_bad? 0: pw2[n - tot];}
}p, q;

int cnt[2];
map<int,int> a[MAXN];

int main(void)
{
	pw2[0] = 1;
	for(int i=1; i<MAXN; ++i) pw2[i] = pw2[i-1] * 2 %mod;
	
	int n,m,Q;
	scanf("%d%d%d",&n,&m,&Q);
	
	p.n = n; p.m = m;
	q.n = m; q.m = n;
	while(Q--)
	{
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		p.update(x, y, k);
		q.update(y, x, k);
		
		if(a[x].find(y) != a[x].end())
		{
			--cnt[a[x][y] ^ (x&1) ^ (y&1)];
			a[x].erase(y);
		}
		if(k != -1)
		{
			++cnt[k ^ (x&1) ^ (y&1)];
			a[x][y] = k;
		}
		
		ll ans = (p.calc() + q.calc()) %mod;
		if(!cnt[0] || !cnt[1]) --ans;
		if(!p.tot && !q.tot) --ans;
		
		ans = (ans + mod) %mod;
		printf("%lld\n",ans);
	}
	return 0;
}