#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200*1000+10;
int n,m, nr;
vi V[nax];
int in[nax],out[nax], par[nax], dep[nax];

void dfs(int x,int p) {
	in[x] = ++nr;
	par[x] = p;
	dep[x] = dep[p] + 1;
	for(auto nbh:V[x]) if(nbh!=p) {
		dfs(nbh,x);
	}
	out[x] = nr;
}

bool cmp(int &a,int &b) {
	return in[a]<in[b];
}

bool is_ancestor(int a,int b) {
	return (in[a]<=in[b]&&in[b]<=out[a])||(in[b]<=in[a]&&in[a]<=out[b]);
}

int main() {_
	cin>>n>>m;
	for(int a,b,i=1; i<n; i++) {
		cin>>a>>b;
		V[a].PB(b);
		V[b].PB(a);
	}
	dfs(1,0);
	out[0] = n+1;
	for(int i=1; i<=m; i++) {
		int k;
		cin>>k;
		vi v;
		v.resize(k);
		pi mx = {-1,-1};
		for(int j=0; j<k; j++) {
			cin>>v[j];
			mx = max(mx,{dep[v[j]],v[j]});
		}
		bool ok = 1;
		for(int j=0; j<k; j++) {
			//if(v[j]==v[j-1]) continue;
			if(!is_ancestor(mx.ND,par[v[j]])) ok = 0;
		}
		if(!ok) cout<<"NO\n";
		else cout<<"YES\n";
	}
	
}