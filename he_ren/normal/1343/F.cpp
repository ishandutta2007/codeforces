#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;

vector<int> a[MAXN];

int p[MAXN], cur;
inline int chk(vector<int> &vec)
{
	int len = (int)vec.size();
	if(len > cur + 1) return 0;
	
	int lef = cur - (len - 1) + 1;
	static bool vis[MAXN];
	for(int i=lef; i<=cur; ++i) vis[p[i]] = 1;
	int has = 0;
	for(int x: vec) if(!vis[x])
	{
		if(has){ has = -1; break;}
		else has = x;
	}
	for(int i=lef; i<=cur; ++i) vis[p[i]] = 0;
	return has == -1? 0: has;
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int k;
		scanf("%d",&k);
		a[i].resize(k);
		for(int &x: a[i]) scanf("%d",&x);
	}
	
	for(int beg=1; beg<=n; ++beg)
	{
		static bool used[MAXN];
		memset(used, 0, (n+1)<<2);
		
		cur = 0;
		p[++cur] = beg;
		while(cur < n)
		{
			bool ok = 0;
			for(int i=1; i<n; ++i) if(!used[i])
			{
				int t = chk(a[i]);
				if(t == 0) continue;
				used[i] = 1;
				p[++cur] = t;
				ok = 1;
				break;
			}
			if(!ok) break;
		}
		
		if(cur == n)
		{
			for(int i=1; i<=n; ++i)
				printf("%d ",p[i]);
			printf("\n");
			return;
		}
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}