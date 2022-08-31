#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	long long n,ans;
	while(t--){
		cin >> n;ans=n*(n+1)/2;
		for(long long int i=1; i<=n ;i*=2) ans-=i*2;
		cout << ans << endl;
	}
}