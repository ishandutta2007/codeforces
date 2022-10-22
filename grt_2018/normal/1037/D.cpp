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
int n;
vi V[nax];
pi in[nax];
int p[nax];

void dfs(int x) {
	for(int nbh:V[x]) if(nbh!=p[x]) {
		p[nbh] = x;
		dfs(nbh);
	}
}

int main() {_
	cin>>n;
	for(int a,b,i=1; i<n;i++) {
		cin>>a>>b;
		V[a].PB(b);
		V[b].PB(a);
	}
	dfs(1);
	in[0] = {1,1};
	int cnt=1;
	for(int a,i=1; i<=n; i++) {
		cin>>a;
		if(in[p[a]].ST>i||i>in[p[a]].ND) {
			cout<<"No"; return 0;
		}
		in[a] = {cnt+1,cnt+V[a].size()-(a==1?0:1)};
		cnt +=V[a].size()-(a==1?0:1);
	}
	cout<<"Yes"; return 0;
}