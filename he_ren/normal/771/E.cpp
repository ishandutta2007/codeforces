#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN], b[MAXN];
ll sum[MAXN][3], pre[MAXN][3];

map<int,int> mem[MAXN];
int dp(int x,int y)
{
	if(x<0 || y<0) return -inf;
	if(mem[x].find(y) != mem[x].end()) return mem[x][y];
	int &res = mem[x][y] = 0;
	
	if(x >= y)
		res = max(res, dp(pre[x][0], y) + 1);
	if(x <= y)
		res = max(res, dp(x, pre[y][1]) + 1);
		
	int t = min(x, y);
	res = max(res, dp(t, t));
	res = max(res, dp(pre[t][2], pre[t][2]) + 1);
	return res;
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	for(int i=1; i<=n; ++i)
	{
		sum[i][0] = sum[i-1][0] + a[i];
		sum[i][1] = sum[i-1][1] + b[i];
		sum[i][2] = sum[i-1][2] + a[i] + b[i];
	}
	
	for(int k=0; k<3; ++k)
	{
		map<ll,int> lst;
		for(int i=0; i<=n; ++i)
		{
			ll cur = sum[i][k];
			if(lst.find(cur) != lst.end())
				pre[i][k] = lst[cur];
			else
				pre[i][k] = -inf;
			lst[cur] = i;
			if(i) pre[i][k] = max(pre[i][k], pre[i-1][k]);
		}
	}
	
	for(int i=0; i<=n; ++i) mem[i].clear();
	printf("%d\n",dp(n,n));
}

int main(void)
{
	int T = 1;
	while(T--) solve();
	return 0;
}