#include<bits/stdc++.h>
using namespace std;
int t,n,u,v,a[100005];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>u>>v;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=2e9;
		for(int i=2;i<=n;i++){
			if(a[i]>a[i-1]+1||a[i]<a[i-1]-1)ans=0;
			if(a[i]==a[i-1]+1)ans=min(ans,min(u,v));
			if(a[i]==a[i-1]-1)ans=min(ans,min(u,v));
		}
		ans=min(ans,v+min(u,v));
		cout<<ans<<'\n';
	}
}