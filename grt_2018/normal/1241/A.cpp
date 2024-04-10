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

int q,n;

int main() {_
	cin>>q;
	while(q--) {
		cin>>n;
		if(n==2) cout<<"2\n";
		else if(n%2) cout<<"1\n";
		else cout<<"0\n";
	}
	
}