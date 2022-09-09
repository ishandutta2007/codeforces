#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN];

int dp[MAXN][MAXN], in[MAXN][MAXN], out[MAXN][MAXN];

void upd(int cur,int x,int y, int k)
{
	if(dp[cur][y] + k < dp[cur][x])
	{
		dp[cur][x] = dp[cur][y] + k;
		in[cur][x] = in[cur][y];
		out[cur][x] = out[cur][y];
	}
}

int main(void)
{
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int dsc[MAXN], dcnt=0;
	for(int i=1; i<=n; ++i) dsc[++dcnt] = a[i];
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1)-dsc-1;
	for(int i=1; i<=n; ++i)
		a[i] = lower_bound(dsc+1,dsc+dcnt+1,a[i])-dsc;
	
	static vector<int> poss[MAXN];
	for(int i=1; i<=n; ++i)
		poss[a[i]].push_back(i);
	
	for(int i=1; i<=n; ++i)
		dp[0][i] = min(abs(i-s), n-abs(i-s));
	
	for(int cur=1; cur<=dcnt; ++cur)
	{
		vector<int> &pos = poss[cur];
		
		for(int i=1; i<=n; ++i)
			dp[cur][i] = inf;
		if((int)pos.size() == 1)
		{
			dp[cur][pos[0]] = dp[cur-1][pos[0]];
			in[cur][pos[0]] = 0;
			out[cur][pos[0]] = 0;
		}
		else
		{
			for(int i=0; i<(int)pos.size(); ++i)
			{
				int lef = (i == 0)? (int)pos.size()-1: i-1;
				int rig = (i == (int)pos.size()-1)? 0: i+1;
				
				int disl = (lef < i)? pos[i] - pos[lef]: n - (pos[lef] - pos[i]);
				int disr = (rig > i)? pos[rig] - pos[i]: n - (pos[i] - pos[rig]);
				
				int froml = dp[cur-1][pos[lef]] + n - disl;
				int fromr = dp[cur-1][pos[rig]] + n - disr;
				
				out[cur][pos[i]] = i;
				if(froml < fromr)
					dp[cur][pos[i]] = froml,
					in[cur][pos[i]] = lef;
				else
					dp[cur][pos[i]] = fromr,
					in[cur][pos[i]] = rig;
			}
		}
		
		for(int k=2; k--;)
		{
			upd(cur, 1, n, 1);
			for(int i=2; i<=n; ++i)
				upd(cur, i, i-1, 1);
			upd(cur, n, 1, 1);
			for(int i=n-1; i>=1; --i)
				upd(cur, i, i+1, 1);
		}
	}
	
	int now = 1;
	for(int i=1; i<=n; ++i)
		if(dp[dcnt][i] < dp[dcnt][now])
			now = i;
	
	printf("%d\n",dp[dcnt][now]);
	
	vector<int> path;
	for(int k=dcnt; k>=1; --k)
	{
		vector<int> &pos = poss[k];
		if(in[k][now] == out[k][now])
		{
			path.push_back(pos[in[k][now]]);
			now = pos[in[k][now]];
			continue;
		}
		
		if((out[k][now] + 1) % (int)pos.size() == in[k][now])
		{
			int u = out[k][now];
			while(1)
			{
				path.push_back(pos[u]);
				if(u == in[k][now]) break;
				--u;
				if(u < 0) u = (int)pos.size() - 1;
			}
		}
		else
		{
			int u = out[k][now];
			while(1)
			{
				path.push_back(pos[u]);
				if(u == in[k][now]) break;
				++u;
				if(u >= (int)pos.size()) u=0;
			}
		}
		
		now = pos[in[k][now]];
	}
	
	reverse(path.begin(), path.end());
	
	int lst = s;
	for(int i=0; i<(int)path.size(); ++i)
	{
		int now = path[i];
		
		if(now >= lst)
		{
			if(now-lst < n-(now-lst)) printf("+%d\n",now-lst);
			else printf("-%d\n",n-(now-lst));
		}
		else
		{
			if(lst-now < n-(lst-now)) printf("-%d\n",lst-now);
			else printf("+%d\n",n-(lst-now));
		}
		
		lst = now;
	}
	return 0;
}