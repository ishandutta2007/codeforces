#include<bits/stdc++.h>
using namespace std;
int n,a[1005][3],f[1005];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][0];
		for(int i=1;i<=n;i++)cin>>a[i][1];
		for(int i=1;i<=n;i++)cin>>a[i][2];
		for(int i=1;i<n;i++){
			if(a[i][0]^f[i-1])cout<<(f[i]=a[i][0])<<' ';
			else cout<<(f[i]=a[i][1])<<' ';
		}
		if(a[n][0]!=f[n-1]&&a[n][0]!=f[1])cout<<a[n][0]<<endl;
		else if(a[n][1]!=f[n-1]&&a[n][1]!=f[1])cout<<a[n][1]<<endl;
		else cout<<a[n][2]<<endl;
	}
	return 0;
}