#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int nax = 100*1000+10;
const ll INF = (ll)1e18;
int n,s;
vi V[nax];
int in[nax];
int p[nax];
int c[nax][3];
int colo[nax];
int odp[nax];
ll ans=INF;

void dfs(int x,int par,int pos) {
	p[pos] = x;
	for(int nbh:V[x]) if(nbh!=par) dfs(nbh,x,pos+1);
}

int main() {_
	cin>>n;
	for(int j=0; j<3; j++) {
		for(int i=1; i<=n; i++) {
			cin>>c[i][j];
		}
	}
	for(int a,b,i=1; i<n; i++) {
		cin>>a>>b;
		V[a].PB(b); V[b].PB(a);
		in[a]++; in[b]++;
	}
	for(int i=1; i<=n; i++) {
		if(in[i]>2) {
			cout<<"-1"; return 0;
		}
		if(in[i]==1) s = i;
	}
	dfs(s,0,1);
	for(int c1=0; c1<3; c1++) {
		for(int c2=0; c2<3; c2++) {
			if(c1==c2) continue;
			ll w = c[p[1]][c1]+c[p[2]][c2];
			colo[1] = c1; colo[2] = c2;
			for(int i=3; i<=n; i++) {
				colo[i] = 3 - colo[i-1]-colo[i-2];
				w+=c[p[i]][colo[i]];
			}
			if(ans>w) {
				ans = w;
				for(int i=1; i<=n; i++) {
					odp[p[i]] = colo[i]+1;
				}
			}
		}
	}
	cout<<ans<<"\n";
	for(int i=1; i<=n; i++) cout<<odp[i]<<" ";
}