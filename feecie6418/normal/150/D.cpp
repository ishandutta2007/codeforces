#include<bits/stdc++.h>
using namespace std;
int n,f[155][155],g[155][155][155],ans[155],w[155];
char a[155],vf[155][155],vg[155][155][155];
int F(int l,int r);
int G(int l,int r,int k);
int G(int l,int r,int k){
	if(k>r-l+1)return -1e9;
	if(vg[l][r][k])return g[l][r][k];
	vg[l][r][k]=1;
	if(!k)return g[l][r][k]=F(l,r);
	if(k==1){
		for(int i=l;i<=r;i++)g[l][r][k]=max(g[l][r][k],F(l,i-1)+F(i+1,r));
		return g[l][r][k];
	}
	if(a[l]==a[r])g[l][r][k]=max(g[l][r][k],G(l+1,r-1,k-2));
	for(int i=l;i<r;i++){
		g[l][r][k]=max(g[l][r][k],F(l,i)+G(i+1,r,k));
		g[l][r][k]=max(g[l][r][k],G(l,i,k)+F(i+1,r));
	}
	return g[l][r][k];
}
int F(int l,int r){
	if(l>r||vf[l][r])return f[l][r];
	vf[l][r]=1;
	for(int k=1;k<=r-l+1;k++)f[l][r]=max(f[l][r],G(l,r,k)+w[k]);
	return f[l][r];
}
int main(){
	cin>>n,memset(g,0xc0,sizeof(g)),memset(f,0xc0,sizeof(f));
	for(int i=1;i<=n;i++){
		cin>>w[i],f[i][i-1]=0;
		if(w[i]<0)w[i]=-1e9;
	}
	f[n+1][n]=0;
	cin>>a+1;
	for(int i=1;i<=n;i++){
		ans[i]=ans[i-1];
		for(int j=1;j<=i;j++)ans[i]=max(ans[i],ans[j-1]+F(j,i));
	}
	cout<<ans[n];
}