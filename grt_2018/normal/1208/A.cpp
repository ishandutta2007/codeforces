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

int t,a,b,n;

int main() {_
	cin>>t;
	while(t--) {
		cin>>a>>b>>n;
		if(n%3==0) {
			cout<<a<<"\n";
		} else if(n%3==1) {
			cout<<b<<"\n";
		} else {
			cout<<(a^b)<<"\n";
		}
	}
}