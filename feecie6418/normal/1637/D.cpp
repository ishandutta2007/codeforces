#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105],b[105],n;
ll f[105][10005],s[105];
void Solve(){
	cin>>n;
	ll S=0;
	for(int i=1;i<=n;i++)cin>>a[i],S+=1ll*(n-1)*a[i]*a[i];
	for(int i=1;i<=n;i++)cin>>b[i],s[i]=s[i-1]+a[i]+b[i],S+=1ll*(n-1)*b[i]*b[i];
	for(int i=0;i<=n;i++)for(int j=0;j<=10000;j++)f[i][j]=1e18;
	f[0][0]=0;
	ll ans=1e18;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=10000;j++){
			if(j>=b[i])f[i][j]=min(f[i][j],f[i-1][j-b[i]]+1ll*(j-b[i])*b[i]+1ll*(s[i-1]-(j-b[i]))*a[i]);
			if(j>=a[i])f[i][j]=min(f[i][j],f[i-1][j-a[i]]+1ll*(j-a[i])*a[i]+1ll*(s[i-1]-(j-a[i]))*b[i]);
			if(i==n)ans=min(ans,f[i][j]);
		}
	}
	cout<<2*ans+S<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--){
		Solve();
	}
}