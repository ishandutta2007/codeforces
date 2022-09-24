#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<n;i++){
		if(a[i-1]==a[i]&&a[i]==a[i+1]){
			cout<<a[i]<<'\n';
			return ;
		}
	}
	puts("-1");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}