#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,a[N]; 
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(a[1]^n&&a[n]^n){
		cout<<-1<<'\n';
		return;
	}
	if(a[1]==n){
		reverse(a+2,a+n+1);	
	}
	else{
		reverse(a+1,a+n);
	}
	for(int i=1;i<=n;++i){
		cout<<a[i]<<' ';
	}
	cout<<'\n'; 
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