#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,a[1005],b[1005];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=x-'0';
	}
	for(int i=1;i<=m&&i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j-1]+a[j+1]==1)b[j]=1;
			if(a[j])b[j]=1;
		}
		for(int j=1;j<=n;j++)a[j]=b[j],b[j]=0;
	}
	for(int j=1;j<=n;j++)cout<<a[j],a[j]=0;
	puts("");
}
int main(){
	cin>>t;
	while(t--)Solve();
}