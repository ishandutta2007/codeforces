#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

vector<int> g[MAXN];

inline int ask(const vector<int> &vec)
{
	printf("? %d ",(int)vec.size());
	for(int x: vec) printf("%d ",x);
	printf("\n"); fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

inline int ask(const vector<pii> &vec)
{
	vector<int> dsc;
	for(pii x: vec) dsc.push_back(x.first), dsc.push_back(x.second);
	sort(dsc.begin(), dsc.end());
	dsc.erase(unique(dsc.begin(), dsc.end()), dsc.end());
	return ask(dsc);
}

vector<pii> es;
void dfs_es(int u,int fa)
{
	for(int v: g[u]) if(v != fa)
	{
		es.push_back(make_pair(u,v));
		dfs_es(v, u);
		es.push_back(make_pair(u,v));
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	dfs_es(1,0);
	
	vector<int> vec;
	for(int i=1; i<=n; ++i) vec.push_back(i);
	int need = ask(vec);
	
	int l = 0, r = (int)es.size() - 1;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(ask(vector<pii>(es.begin() + l, es.begin() + mid + 1)) == need) r = mid;
		else l = mid + 1;
	}
	
	printf("! %d %d\n",es[l].first,es[l].second);
	fflush(stdout);
	return 0;
}