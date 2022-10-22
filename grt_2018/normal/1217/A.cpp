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

int T,s,i,e;

int main() {_
	cin>>T;
	while(T--) {
		cin>>s>>i>>e;
		int sm = s+e-i-1;
		if(sm<0) cout<<"0\n";
		else cout<<min(sm/2,e)+1<<"\n";
	}
}