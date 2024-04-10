#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,f[3005][3005],nxt[3005],a[3005],lst[3005];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=1e9;
	for(int i=1;i<=n;i++)cin>>a[i],f[i][i]=f[i][i-1]=0,lst[i]=n+1;
	for(int i=n;i>=1;i--)nxt[i]=lst[a[i]],lst[a[i]]=i;
	for(int k=2;k<=n;k++){
		for(int i=1;i+k-1<=n;i++){
			int j=i+k-1;
			if(a[i]==a[j])f[i][j]=f[i+1][j-1]+(a[i]!=a[i+1]);
			else f[i][j]=f[i+1][j]+(a[i]!=a[i+1]);
			for(int k=nxt[i];k<=j;k=nxt[k])f[i][j]=min(f[i][j],f[i][k-1]+f[k][j]);
		}
	}
	cout<<f[1][n]<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}