#include<bits/stdc++.h>
using namespace std;
char rb[2000005];
int pt=2000000;
char gc(){
	if(pt>=2000000)fread(rb,1,2000000,stdin),pt=0;
	return rb[pt++];
}
int rd(){
	int x=0,ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))x=x*10+ch-'0',ch=gc();
	return x;
}
int n,m,K,a[105][105],fa[105],f2[105];
bitset<105> f[105];
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
int main(){
	n=rd(),m=rd(),K=rd();
	for(int i=1;i<=n;i++)fa[i]=i;
	int ans=K+1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=rd(),f[i][j]=a[i][j];
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(f[i]==f[j])fa[gf(i)]=gf(j);
	if(n>K){
		for(int i=1;i<=n;i++){
			if(gf(i)!=i)continue;
			int cur=0;
			for(int j=1,t;j<=n;j++)t=(f[i]^f[j]).count(),cur+=min(t,m-t);
			ans=min(ans,cur);
		}
	}
	else {
		for(int j=1;j<=m;j++)for(int i=1;i<=n;i++)if(a[i][j])f2[j]|=1<<i-1;
		for(int i=0;i<(1<<n);i++){
			int cur=__builtin_popcount(i^f2[1]);
			for(int j=2,t;j<=m&&cur<ans;j++)t=__builtin_popcount(i^f2[j]),cur+=min(t,n-t);
			ans=min(ans,cur);
		}
	}
	printf("%d\n",ans>K?-1:ans);
	return 0;
}