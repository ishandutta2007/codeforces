#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,jc[4045]={1},ny[4045]={1},ans=0,t1[4045],t2[4045],t3[4045];
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
} 
int C(int x,int y){
	if(x<0||y<0||x<y)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int main(){
	for(int i=1;i<=4040;i++)jc[i]=1ll*jc[i-1]*i%mod,ny[i]=Power(jc[i],mod-2);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		for(int t=m;t>=1;t--)t1[t]=(t1[t+1]+C(m-t+n-i-1,n-i-1))%mod;
		for(int l=m;l>=1;l--)t1[l]=(t1[l+1]+1ll*C(l-1+n-i-1,n-i-1)*t1[l])%mod;
		for(int k=m;k>=1;k--)t2[k]=(t2[k+1]+1ll*C(m-k+i-1,i-1)*t1[k+2])%mod;
		for(int j=m;j>=1;j--)t2[j]=(t2[j+1]+1ll*C(j-1+i-1,i-1)*t2[j])%mod;
		ans=(ans+t2[1])%mod;
	}
	//j-1i+1 
	for(int k=1;k<m;k++){
		for(int j=n;j>=1;j--)t3[j]=(t3[j+1]+1ll*C(k-1+j-1,j-1)*C(k+n-j,n-j))%mod;
		for(int i=1;i<=n;i++)ans=(ans+1ll*C(m-k-1+n-i,n-i)*C(m-k+i-1,i-1)%mod*t3[i+1])%mod;
	}
	cout<<2*ans%mod;
}