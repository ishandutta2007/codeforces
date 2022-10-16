#include<bits/stdc++.h>
using namespace std;
#define pb cout<<"NO\n"
#define py cout<<"YES\n";
int T,n,i,j,a[1005];
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n+n;++i)cin>>a[i];
		sort(a+1,a+n+n+1);
		for(i=1;i<=n;++i)cout<<a[i]<<" "<<a[n+n-i+1]<<" ";
		cout<<"\n";
	}
}