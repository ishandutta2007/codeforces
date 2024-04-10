#include<bits/stdc++.h>
using namespace std;
int ans[3005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,ans=2e9;
		cin>>n;
		for(int i=1;i<=40000;i++)ans=min(ans,i-1+(n+i-1)/i-1);
		cout<<ans<<endl;
	}
}