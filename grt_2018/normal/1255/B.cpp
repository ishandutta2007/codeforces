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

const int nax = 1000+10;
int t,n,m;
ll ans;
pi a[nax];

int main() {_
	cin>>t;
	while(t--) {
		cin>>n>>m;
		ans = 0;
		for(int i=0; i<n; i++) {
			cin>>a[i].ST;
			a[i].ND = i+1;
			ans+=2*a[i].ST;
		}
		sort(a,a+n);
		m-=n;
		if(m<0||n==2) {
			cout<<"-1\n";
			continue;
		}
		ans+=(ll)m*(a[0].ST+a[1].ST);
		cout<<ans<<"\n";
		for(int i=0; i<m; i++) {
			cout<<a[0].ND<<" "<<a[1].ND<<"\n";
		}
		for(int i=0; i<n; i++) {
			cout<<a[i].ND<<" "<<a[(i+1)%n].ND<<"\n";
		}
	}
		
			
	
}