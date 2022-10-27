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
		int a, b, n;
		cin>>a>>b>>n;
		if(n%3 == 0){
			cout<<a<<endl;
		}else if(n%3 == 1){
			cout<<b<<endl;
		}else{
			cout<<(a^b)<<endl;
		}
	}

	return 0;
}