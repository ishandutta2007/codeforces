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

const int nax = 5000+10;
int n,m,k=1;
int visited[nax];
int c[nax];
vector<pi> V[nax];

void dfs(int x) {
	visited[x] = 1;
	for(auto it:V[x]) {
		if(visited[it.ST]==1) {
			c[it.ND] = 2;
			k = 2;
		} else if(visited[it.ST]==0) {
			c[it.ND] = 1;
			dfs(it.ST);
		} else {
			c[it.ND] = 1;
		}
	}
	visited[x] = 2;
}

int main() {_
	cin>>n>>m;
	for(int a,b,i=0; i<m;i++) {
		cin>>a>>b;
		V[a].PB({b,i});
	}
	for(int i=1; i<=n; i++) {
		if(visited[i]==0) dfs(i);
	}
	cout<<k<<"\n";
	for(int i=0; i<m; i++) {
		cout<<c[i]<<" ";
	}
}