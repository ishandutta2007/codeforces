#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,B=2000;
int n,f[2005][4005],g[2005][4005];
//f g 
char a[2005],b[2005];
void upd(int &x,int y){
	x=(x+y)%mod;
} 
void Solve(){
	cin>>n>>a+1>>b+1,f[0][B]=1;
	for(int i=1;i<=n;i++){
		if(i%2==0&&a[i]!='?')a[i]^=1;
		if(i%2==0&&b[i]!='?')b[i]^=1;
		for(int j=B-i+1;j<=B+i-1;j++){
			for(int k=0;k<2;k++){
				for(int l=0;l<2;l++){
					if(a[i]!='?'&&a[i]!=k+'0')continue;
					if(b[i]!='?'&&b[i]!=l+'0')continue;
					upd(f[i][j+k-l],f[i-1][j]);
					upd(g[i][j+k-l],(1ll*f[i-1][j]*abs(j-B+k-l)+g[i-1][j])%mod);
				}
			}
		}
	}
	cout<<g[n][B]<<'\n';
	for(int i=0;i<=n;i++)for(int j=B-n;j<=B+n;j++)f[i][j]=g[i][j]=0;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}