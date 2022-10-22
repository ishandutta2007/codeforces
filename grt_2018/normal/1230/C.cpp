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

const int nax = 8;
int n,m;
int ans;
pi edges[nax*nax];
int in[nax];
set<pi>S;

int main() {_
	cin>>n>>m;
	for(int i=0; i<m;i++) {
		cin>>edges[i].ST;
		cin>>edges[i].ND;
		if(edges[i].ST>edges[i].ND) swap(edges[i].ST,edges[i].ND);
		S.insert(edges[i]);
		in[edges[i].ST]++;
		in[edges[i].ND]++;
	}
	if(n!=7) {
		cout<<(int)S.size();
	} else {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n ;j++) {
				int cnt = 0;
				for(int k=1; k<=n; k++) {
					if(k==i||k==j) continue;
					if(S.find({min(i,k),max(i,k)})!=S.end()&&S.find({min(j,k),max(j,k)})!=S.end()) {
						cnt++;
					}
				}
				ans = max(ans,(int)S.size()-cnt);
			}
		}
		cout<<ans;
	}
			
					
			
	
}