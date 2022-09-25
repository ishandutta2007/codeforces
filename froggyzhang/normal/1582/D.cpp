#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,a[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	if(n&1){
		if(-a[2]-a[3]!=0)cout<<(-a[2]-a[3])<<' '<<a[1]<<' '<<a[1]<<' ';
		else cout<<(-a[2]+a[3])<<' '<<a[1]<<' '<<(-a[1])<<' ';
		for(int i=4;i<n;i+=2){
			cout<<a[i+1]<<' '<<(-a[i])<<' ';
		}
	}
	else{
		for(int i=1;i<n;i+=2){
			cout<<a[i+1]<<' '<<(-a[i])<<' ';
		}
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}