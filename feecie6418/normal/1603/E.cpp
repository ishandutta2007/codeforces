#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int inf=1e9;
int n,mod,ans=0,jc[205]={1},ny[205]={1};
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return r;
}
void upd(int &x,int y){
	x=(x+y)%mod;
}
int main(){
	cin>>n>>mod;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod,ny[i]=Power(jc[i],mod-2);
	for(int i=1;i<=n+1;i++){
		map<int,int> f[205],g[205];
		f[0][inf]=1;//x a_1<=y 
		for(int j=n+1;j>=i;j--){
			for(int k=0;k<n;k++){
				for(auto l:f[k]){
					for(int t=1;t+k<=n&&j*t<=l.first;t++){
						//<=l-i*j
						//
						int nw=min(l.first-j*t,(i-t)*j);
						if(nw<i*(n-k-t))continue;
						upd(g[k+t][nw],1ll*l.second*ny[t]%mod);
					}
				}
			}
			if(j!=i){
				for(int k=0;k<=n;k++){
					for(auto l:g[k])upd(f[k][l.first],l.second);
					g[k].clear();
				}
			}
			else {
				for(int k=0;k<=n;k++)f[k]=g[k];
			}
		}
		for(auto j:f[n])ans=(ans+1ll*j.second*jc[n])%mod;
	}
	cout<<ans;
}