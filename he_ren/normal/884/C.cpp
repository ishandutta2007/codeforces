#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int p[MAXN],size[MAXN];
bool vis[MAXN];

void dfs(int fa,int u)
{
	vis[u]=1;
	if(p[u]==fa) return;
	size[p[u]] = size[u]+1;
	dfs(fa,p[u]);
	size[u] = size[p[u]];
}

vector<int> t;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	ll ans=0;
	for(int i=1; i<=n; ++i)
		if(!vis[i])
		{
			size[i]=1;
			dfs(i,i);
			t.push_back(size[i]);
			ans += (ll)size[i]*size[i];
		}
	
	if(t.size()==1) cout<<ans;
	else
	{
		sort(t.begin(),t.end());
		reverse(t.begin(),t.end());
		cout<<ans + 2ll*t[0]*t[1];
	}
	return 0;
}