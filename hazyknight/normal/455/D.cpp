#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 100005;
const int S = 320;

struct Val
{
	int val;
	int pre,nxt;
}node[MAXN];

int n,q,tot;
int last_ans;
int pos[MAXN];
int head[MAXN];
int tail[MAXN];
int cnt[S][MAXN];

void build(int id)
{
	pos[0] = pos[tot + 1] = -1;
	head[id] = pos[1];
	tail[id] = pos[tot];
	for (int i = 1;i <= tot;i++)
	{
		node[pos[i]].pre = pos[i - 1];
		node[pos[i]].nxt = pos[i + 1];
	}
}

int main()
{
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		node[i].pre = node[i].nxt = -1;
		scanf("%d",&node[i].val);
	}
	for (int L = 0,R = S - 1;L < n;L = R + 1)
	{
		R = min(L + S - 1,n - 1);
		tot = 0;
		int id = L / S;
		for (int j = L;j <= R;j++)
		{
			pos[++tot] = j;
			cnt[id][node[j].val]++;
		}
		build(id);
	}
	scanf("%d",&q);
	while (q--)
	{
		int tp,l,r,k;
		scanf("%d%d%d",&tp,&l,&r);
		l = (l + last_ans - 1) % n;
		r = (r + last_ans - 1) % n;
		if (l > r)
			swap(l,r);
		int L = l / S,R = r / S;
		if (tp == 1)
		{
			if (L == R)
			{
				tot = 0;
				int j = head[L];
				for (int i = L * S;i < l;i++,j = node[j].nxt)
					pos[++tot] = j;
				int tmp = tot + 1;
				tot++;
				for (int i = l;i < r;i++,j = node[j].nxt)
					pos[++tot] = j;
				pos[tmp] = j;
				j = node[j].nxt;
				for (int i = r + 1;i < min((L + 1) * S,n);i++,j = node[j].nxt)
					pos[++tot] = j;
				build(L);
			}
			else
			{
				int lst = tail[L];
				cnt[L][node[lst].val]--;
				for (int i = L + 1;i < R;i++)
				{
					node[lst].nxt = head[i];
					node[head[i]].pre = lst;
					head[i] = lst;
					cnt[i][node[lst].val]++;
					lst = tail[i];
					tail[i] = node[lst].pre;
					cnt[i][node[lst].val]--;
					node[lst].pre = node[lst].nxt = -1;
				}
				tot = 0;
				pos[++tot] = lst;
				cnt[R][node[lst].val]++;
				int j = head[R];
				for (int i = R * S;i < r;i++,j = node[j].nxt)
					pos[++tot] = j;
				lst = j;
				cnt[R][node[lst].val]--;
				j = node[j].nxt;
				for (int i = r + 1;i < min((R + 1) * S,n);i++,j = node[j].nxt)
					pos[++tot] = j;
				build(R);
				tot = 0;
				j = head[L];
				cnt[L][node[lst].val]++;
				for (int i = L * S;i < l;i++,j = node[j].nxt)
					pos[++tot] = j;
				pos[++tot] = lst;
				for (int i = l;i < min((L + 1) * S - 1,n - 1);i++,j = node[j].nxt)
					pos[++tot] = j;
				build(L);
			}
		}
		else
		{
			scanf("%d",&k);
			k = (k + last_ans - 1) % n + 1;
			last_ans = 0;
			if (L == R)
			{
				int j = head[L];
				for (int i = L * S;i <= r;i++,j = node[j].nxt)
					if (i >= l)
						last_ans += (node[j].val == k);
				printf("%d\n",last_ans);
			}
			else
			{
				int j = tail[L];
				for (int i = min((L + 1) * S - 1,n - 1);i >= l;i--,j = node[j].pre)
					last_ans += (node[j].val == k);
				j = head[R];
				for (int i = R * S;i <= r;i++,j = node[j].nxt)
					last_ans += (node[j].val == k);
				for (int i = L + 1;i < R;i++)
					last_ans += cnt[i][k];
				printf("%d\n",last_ans);
			}
		}
	}
	return 0;
}