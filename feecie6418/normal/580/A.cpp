#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int ans=0,t=0,n;
    cin>>n>>a[1]; 
    for(int i=2;i<=n;i++){
    	cin>>a[i];
    	if(a[i]>=a[i-1])t++,ans=max(ans,t);
    	else t=0;
	}   
    cout<<ans+1;
    return 0;
}