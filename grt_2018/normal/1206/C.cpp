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
int n;
ll s,s2;
int t[2*nax];

int main() {_
	cin>>n;
	s = (ll)n*(2*n+1);
	for(int i=1; i<=n;i++) {
		if(i%2==1) {
			t[i] = i*2-1;
			t[i+n] = i*2;
		} else {
			t[i] = i*2;
			t[i+n] = i*2-1;
		}
	}
	for(int i=1; i<=n;i++) s2+=t[i];
	for(int i=1; i<=n+1; i++) {
		if(s%2==0&&s2!=s/2) {
			cout<<"NO"; return 0;
		}
		else if(s2!=s/2&&s2!=(s+1)/2) {
			cout<<"NO"; return 0;
		}
		s2-=t[i]; s2+=t[i+n];
	}
	cout<<"YES\n";
	for(int i=1; i<=2*n;i++) cout<<t[i]<<" ";
}