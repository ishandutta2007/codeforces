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
		int a, b;
		cin>>a>>b;
		if(__gcd(a, b) == 1){
			cout<<"Finite"<<endl;
		}else{
			cout<<"Infinite"<<endl;
		}
	}

	return 0;
}