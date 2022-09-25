#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int n;
	cin>>n;
	for(int i=2;i<n-2;++i){
		if(__gcd(i,n-1-i)==1){
			cout<<i<<' '<<n-1-i<<' '<<1<<'\n';
			return;	
		}	
	}
	assert(false);	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}