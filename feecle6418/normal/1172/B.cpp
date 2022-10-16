#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,K,jc[200005]={1},ny[200005]={1},ans=0,d[200005];
int C(int x,int y){
	if(x<y||y<0||x<0)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[n]=Power(jc[n],mod-2);
	for(int i=n-1;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		d[x]++,d[y]++;
	}
	int s=n;
	for(int i=1;i<=n;i++){
		if(i!=1)s=1ll*s*jc[d[i]]%mod;
		else s=1ll*s*jc[d[i]]%mod;
	}
	cout<<s;
}