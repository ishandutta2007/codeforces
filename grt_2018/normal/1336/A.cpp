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
int n,k;
vi V[nax];
int val[nax],sz[nax],dep[nax];

void dfs(int x,int p) {
	dep[x] = dep[p] + 1;
	for(int nbh : V[x]) {
		if(nbh != p) {
			dfs(nbh,x);
			sz[x] += sz[nbh] + 1;
		}
	}
	val[x] = dep[x] - sz[x];
}

int main() {_
	cin >> n >> k;
	for(int a,b,i=1; i<n; ++i) {
		cin >> a >> b;
		V[a].PB(b);
		V[b].PB(a);
	}
	dep[0] = -1;
	dfs(1,0);
	sort(val+1,val+n+1);
	ll sum = 0;
	for(int i = n; i > n-k; i--) {
		sum += val[i];
	}
	cout << sum;
}