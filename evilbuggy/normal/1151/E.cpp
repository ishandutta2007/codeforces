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

	int n, x;
	cin>>n;
	int p = 0;
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		cin>>x;
		if(x == p)continue;
		if(x < p){
			ans += 1LL*x*(p-x);
		}else{
			ans += 1LL*(n-x+1)*(x-p);
		}
		p = x;
	}
	cout<<ans<<endl;
	
	return 0;
}