#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--){
		int n, m, k;
		cin>>n>>m>>k;
		int r = n/k;
		int mx = min(r, m);
		m -= mx;
		int mn = (m + k - 2)/(k - 1);
		cout<<mx - mn<<'\n';
	}

	return 0;
}