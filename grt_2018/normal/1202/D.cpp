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

int n,t,cnt3,cnt7;

int main() {_
	cin>>t;
	while(t--) {
	cin>>n;
	cnt3 = 2;
	while((ll)(cnt3+1)*cnt3/2<=n) cnt3++;
	cnt7 = n - (cnt3)*(cnt3-1)/2;
	cout<<"133";
	cnt3-=2;
	if(cnt7>0)
	while(cnt7--) cout<<"7";
	if(cnt3>0)
	while(cnt3--) cout<<"3";
	cout<<"7\n";
}
}