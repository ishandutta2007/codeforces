#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
int n,a[N];
void Solve(){
	cin>>n;
	ll g=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		g=i==1?2:g/__gcd(g,(ll)i+1)*(i+1);
		if(g>1e9)break;
		if(a[i]%g==0){
			cout<<"NO\n";
			return;
		}
	}	
	cout<<"YES\n";
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