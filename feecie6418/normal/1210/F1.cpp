#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef bitset<130> B;
unordered_map<B,int> id;
int trans[70005][130],p[10][10],tot,f[10][70005],n;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return r;
}
int dfs(B cur){
	if(id.count(cur))return id[cur];
	int w=++tot;
	B t[10],tmp;
	id[cur]=w;
	for(int i=0;i<n;i++)for(int j=0;j<(1<<n);j++)if(cur[j])t[i][j|(1<<i)]=1;
	for(int i=0;i<(1<<n);i++){
		tmp=cur;
		for(int j=0;j<n;j++)if(i&(1<<j))tmp|=t[j];
		trans[w][i]=dfs(tmp);
	}
	return w;
}
int main(){
	cin>>n;
	for(int i=0,inv100=Power(100,mod-2);i<n;i++)for(int j=0;j<n;j++)cin>>p[i][j],p[i][j]=1ll*inv100*p[i][j]%mod;
	B tmp;
	tmp[0]=1,f[0][dfs(tmp)]=1;
	for(int i=0;i<n;i++){
		for(int j=1;j<=tot;j++){
			for(int k=0;k<(1<<n);k++){
				int pro=1;
				for(int w=0;w<n;w++)if(k&(1<<w))pro=1ll*pro*p[w][i]%mod;else pro=1ll*pro*(1-p[w][i]+mod)%mod;
				f[i+1][trans[j][k]]=(f[i+1][trans[j][k]]+1ll*pro*f[i][j])%mod;
			}
		}
	}
	for(int i=0;i<(1<<n);i++)tmp[i]=1;
	cout<<f[n][id[tmp]];
}