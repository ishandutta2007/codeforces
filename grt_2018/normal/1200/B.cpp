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

const int nax = 100+10;
int t,n,m,k;
int h[nax];

int main() {_
	cin>>t;
	while(t--) {
		cin>>n>>m>>k;
		bool ok=1;
		for(int i=0; i<n;i++) cin>>h[i];
		for(int i=0; i<n-1; i++) {
			if(h[i+1]-k<=h[i]) {
				m+=h[i]-max(h[i+1]-k,0);
			} else {
				int d = (h[i+1]-k)-h[i];
				if(d>m) ok=0;
				else m-=d;
			}
		}
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
				
}