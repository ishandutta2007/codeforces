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
int n,m,ans;
vi V[nax];
bool visited[nax];

void dfs(int x,int &ma) {
	visited[x] = 1;
	ma = max(ma,x);
	for(auto nbh:V[x]) if(!visited[nbh]) dfs(nbh,ma);
}

int main() {_
	cin>>n>>m;
	for(int a,b,i=0; i<m; i++) {
		cin>>a>>b;
		V[a].PB(b);
		V[b].PB(a);
	}
	int w = 1;
	while(w<=n) {
		if(!visited[w]) {
			int ma = 0;
			dfs(w,ma);
			while(w<ma) {
				if(!visited[w]) {
					dfs(w,ma);
					ans++;
				}
				w++;
			}
		}
		w++;
	}
	cout<<ans;		
		
	
}