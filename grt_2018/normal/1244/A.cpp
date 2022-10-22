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

int q,a,b,c,d,k;

int main() {_
	cin>>q;
	while(q--) {
		cin>>a>>b>>c>>d>>k;
		int x = (a-1)/c+1;
		int y = (b-1)/d+1;
		if(x+y>k) cout<<"-1\n";
		else cout<<x<<" "<<y<<"\n";
	}
}