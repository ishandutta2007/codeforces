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
		ll a, b, c;
		cin>>a>>b>>c;
		if(a >= c){
			cout<<-1<<" ";
		}else{
			cout<<1<<" ";
		}
		if(a > c){
			cout<<1<<'\n';
		}else if(b*a > c){
			cout<<b<<'\n';
		}else{
			cout<<-1<<'\n';
		}
	}

	return 0;
}