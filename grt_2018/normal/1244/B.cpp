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

int t,n;
string s;

int main() {_
	cin>>t;
	while(t--) {
		cin>>n>>s;
		int ans = n;
		for(int i=0; i< n;i++) {
			if(s[i]=='1') {
				ans = max(ans,2*max(i+1,n-i));
			}
		}
		cout<<ans<<"\n";
	}
}