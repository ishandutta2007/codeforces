#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define debug if(1)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 3500+10,INF=1e9;
int t,n,m,k;
int a[nax],best[nax];

int main() {_
	cin>>t;
	while(t--) {
		cin>>n>>m>>k;
		m--;
		k = min(k,m);
		int ans = 0;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=0; i<=m; i++) {
			best[i] = max(a[i+1],a[n-(m-i)]);
			//~ debug cout<<best[i]<<" ";
		}
		//~ debug cout<<"\n";
		for(int i=0; i<=k; i++) {
			int w = INF;
			for(int j=0; j<=m; j++) {
				if(i<=j&&(k-i)<=(m-j)) {
					w = min(w,best[j]);
					//~ debug cout<<i<<" "<<j<<"\n";
				}
			}
			ans=max(ans,w);
		}
		cout<<ans<<"\n";
	}
	
}