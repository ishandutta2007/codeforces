#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pr;
const int mod=1e9+7,N=2e6;
db f[105][105][1005],C,allt,pw[1005]={1};
int n;
pr a[105];
void Solve(){
	cin>>n>>C>>allt;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	sort(a+1,a+n+1,[](pr x,pr y){return x>y;});
	memset(f,0x63,sizeof(f));
	f[0][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=1000;k++){
				f[i][j][k]=f[i-1][j][k];
				if(j&&k>=a[i].second){
					f[i][j][k]=min(f[i][j][k],f[i-1][j-1][k-a[i].second]+a[i].first*pw[j]);
				}
			}
		}
	}
	int ans=0;
	for(int j=0;j<=n;j++){
		for(int k=1;k<=1000;k++){
			if(f[n][j][k]>1e18)continue;
			db t=10*j+2*sqrt(f[n][j][k]/C)-1/C;
			if(f[n][j][k]*C<1)t=10*j+f[n][j][k];
			if(t<=allt)ans=max(ans,k);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	for(int i=1;i<=100;i++)pw[i]=pw[i-1]/0.9;
	int t;
	cin>>t;
	while(t--)Solve();
}