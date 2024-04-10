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

const int nax = 100;
int n,ans;
int val[nax],t[nax];
map<vi,int>M;


int main() {_
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>val[i];
		t[i] = val[i]&((1<<15)-1);
	}
	for(int x=0; x<(1<<15); x++) {
		vi tmp = {};
		for(int i=0; i<n; i++) {
			tmp.PB(__builtin_popcount(t[i]^x));
		}
		for(int i=1; i<n; i++) {
			tmp[i] = tmp[i]-tmp[0];
		}
		tmp[0] = 0;
		M[tmp] = x;
	}
	for(int i=0; i<n;i++) t[i] = val[i]>>15;
	for(int x=0;x<(1<<15);x++) {
		vi tmp={};
		for(int i=0; i<n; i++) {
			tmp.PB(__builtin_popcount(t[i]^x));
		}
		for(int i=1; i<n;i++) tmp[i] = tmp[0]-tmp[i];
		tmp[0] = 0;
		if(M.find(tmp)!=M.end()) {
			ans = (x<<15)+M[tmp];
			cout<<ans;
			return 0;
		}
	}
	cout<<"-1";
	
}