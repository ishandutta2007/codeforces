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

const int nax = 200*1000+10,INF=1e9;
int t,n;
int p[nax], in[nax], c[nax];
vector<vi>cycle;
vi cyc;

void add_cycle(int x) {
	if(in[x]==0) return;
	cyc.PB(x);
	in[x]--;
	add_cycle(p[x]);
}

bool check(vi v, int step) {
	for(int i=0; i<step; i++) {
		bool ok = 1;
		for(int j = i+step; j!=i; j+=step) {
			j%=(int)v.size();
			if(i==j) break;
			if(c[v[j]]!=c[v[i]]) ok = 0;
		}
		if(ok) return 1;
	}
	return 0;
}

int main() {_
	cin >> t;
	while(t--) {
		cin >> n;
		int ans = INF;
		for(int i=1; i<=n; ++i) in[i] = 0;
		for(int i=1; i<=n; ++i) {
			cin >> p[i];
			in[p[i]]++;
		}
		cycle.clear();
		for(int i=1; i<=n; ++i) cin >> c[i];
		for(int i=1; i<=n; ++i) {
			if(in[i]==1) {
				cyc.clear();
				add_cycle(i);
				cycle.PB(cyc);
			}
		}
		for(auto cc: cycle) {
			int m = (int)cc.size();
			for(int d=1; d*d<=m; d++) {
				if(m%d==0) {
					//cout<<d<<"\n";
					if(check(cc,d)) {
						ans = min(ans,d);
					}
					if(check(cc,m/d)) {
						ans = min(ans,m/d);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
		
	
}