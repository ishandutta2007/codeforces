#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN], b[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	memset(b, 0, (n+1)<<2);
	static vector<int> g[MAXN];
	for(int i=1; i<=n; ++i) g[i].clear();
	for(int i=1; i<=n; ++i) g[a[i]].push_back(i);
	
	vector<int> vec;
	for(int i=1; i<=n; ++i)
		if(g[i].size()) vec.push_back(i);
	while(vec.size())
	{
		vector<int> pos, val, nxt;
		for(int u: vec)
		{
			int x = g[u].back(); g[u].pop_back();
			pos.push_back(x);
			val.push_back(a[x]);
			if(g[u].size()) nxt.push_back(u);
		}
		if(val.size() > 1) rotate(val.begin(), val.begin()+1, val.end());
		for(int i=0; i<(int)val.size(); ++i)
			b[pos[i]] = val[i];
		vec.swap(nxt);
	}
	
	for(int i=1; i<=n; ++i) printf("%d ",b[i]);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}