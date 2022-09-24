#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int f[505][505],n,a[505],pos[505],ans=0;
void upd(int &x,int y){
	x=(x+y)%mod;
}
int main(){
	cin>>n;
	for(int i=1,x;i<=n;i++){
		char c;
		cin>>c;
		if(c=='+')cin>>x,a[i]=x;
	}
	for(int t=1;t<=n;t++){
		if(!a[t])continue;
		memset(f,0,sizeof(f)),f[0][0]=1;
		int p=t;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				if(!a[i]){
					if(i<=p||j)upd(f[i][max(j-1,0)],f[i-1][j]);
				}
				else {
					if(a[i]<a[t]||(a[i]==a[t]&&i<t))upd(f[i][j+1],f[i-1][j]);
					else upd(f[i][j],f[i-1][j]);
				}
				if(i!=t)upd(f[i][j],f[i-1][j]);
			}
		}
		for(int i=0;i<=n;i++)ans=(ans+1ll*f[n][i]*a[t])%mod;
	}
	cout<<ans;
}