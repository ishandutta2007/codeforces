#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100005];
bool vis[100005];
long long ans;
struct UF{
	int a[100005];
	long long el[100005];	

	int find(int x){
		if(a[x] == -1)
			return x;
		return a[x]=find(a[x]);
	}

	void join(int x, int y, int fac){
		x=find(x);
		y=find(y);
		if(x == y)
			return;
		a[x]=y;
		ans += el[x]*el[y]*fac;
		el[y] += el[x];
	}
}uf;

vector<pair<int, int> > v;

int main(){
	scanf("%d%d", &n, &m);	
	for(int i=0; i < 100005; ++i){
		uf.a[i]=-1;
		uf.el[i]=1;
	}
	for(int i=0; i < n; ++i){
		int ani;
		scanf("%d", &ani);
		v.push_back(make_pair(-ani, i));
	}
	sort(v.begin(), v.end());
	for(int i=0; i < m; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0; i < n; ++i){
		int ani=-v[i].first;
		int ind=v[i].second;
		vis[ind]=1;
		for(int j=0; j < adj[ind].size(); ++j){
			int to=adj[ind][j];
			if(!vis[to])
				continue;
			uf.join(ind, to, ani);
		}
	}
	printf("%lf\n",(2*ans)/((n+0.0)*(n-1)));
}