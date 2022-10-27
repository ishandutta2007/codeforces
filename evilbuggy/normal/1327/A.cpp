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

	ll n, k;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		if(k%2 == n%2){
			if(n >= k*k){
				cout<<"YES"<<'\n';
			}else{
				cout<<"NO"<<'\n';
			}
		}else{
			cout<<"NO"<<'\n';
		}
	}

	return 0;
}