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

const int nax = 100*1000+10;
int n,k,ans;
vi V[nax];
bool visited[nax];

void dfs(int x) {
	visited[x] = 1;
	for(auto nbh:V[x]) {
		if(visited[nbh]) ans++;
		else dfs(nbh);
	}
}

int main() {_
	cin>>n>>k;
	for(int a,b,i=0; i<k;i++) {
		cin>>a>>b;
		V[a].PB(b); V[b].PB(a);
	}
	for(int i=1; i<=n;i++) {
		if(!visited[i]) dfs(i);
	}
	cout<<ans-k;
}