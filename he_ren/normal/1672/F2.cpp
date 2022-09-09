#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int n;
int a[MAXN];

vector<int> h[MAXN];
bool vis[MAXN], insta[MAXN], valid;
void dfs(int u)
{
	if(vis[u]) return;
	if(!valid) return;
	vis[u] = insta[u] = 1;
	for(int v: h[u])
	{
		if(insta[v]) valid = 0;
		else if(!vis[v]) dfs(v);
		if(!valid) return;
	}
	insta[u] = 0;
}
int b[MAXN];

void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	static int bak[MAXN];
	memset(bak, 0, (n+1)<<2);
	for(int i=1; i<=n; ++i) ++bak[a[i]];
	int mx = max_element(bak+1,bak+n+1) - bak;
	
	for(int i=1; i<=n; ++i)
	{
		h[i].clear();
		vis[i] = insta[i] = 0;
	}
	valid = 1;
	
	for(int i=1; i<=n; ++i)
	{
		int u = a[i], v = b[i];
		if(u != mx && v != mx) h[u].push_back(v);
	}
	
	for(int i=1; i<=n; ++i)
		dfs(i);
	
	if(valid)
		printf("AC\n");
	else
		printf("WA\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}