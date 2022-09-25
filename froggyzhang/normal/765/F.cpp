#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define B 420
typedef long long ll;
const int inf=0x3f3f3f3f;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,pos[N],L[B],R[B],blocks,len,p[N],Q;
int a[N],b[N],c[N],f[B][N],g[B][B];
inline int Abs(int x){return x>=0?x:-x;}
void Merge(int l1,int r1,int l2,int r2,int *f){
	for(int i=l1,j=l2;i<=r1;++i){
		while(j<r2&&c[j+1]<=c[i])++j;
		f[i]=min(f[i],min(Abs(c[i]-c[j]),j==r2?inf:Abs(c[i]-c[j+1])));
	}
}
int Query(int l,int r){
	int x=pos[l],y=pos[r],ans=inf;
	if(x==y){
		int las=-1;
		for(int i=L[x];i<=R[x];++i){
			if(p[i]>=l&&p[i]<=r){
				if(~las)ans=min(ans,b[i]-las);
				las=b[i];
			}
		}
	}
	else{
		static int tmp[N];
		ans=min(g[x+1][y-1],min(f[x+1][r],f[y-1][l]));
		for(int i=l;i<=R[x];++i)tmp[i]=inf;
		for(int i=L[x],j=l;i<=R[x];++i){
			if(p[i]>=l)c[j++]=b[i];
		}
		for(int i=L[y],j=L[y];i<=R[y];++i){
			if(p[i]<=r)c[j++]=b[i];
		}
		for(int i=l+1;i<=R[x];++i)ans=min(ans,c[i]-c[i-1]);
		for(int i=L[y]+1;i<=r;++i)ans=min(ans,c[i]-c[i-1]);
		Merge(l,R[x],L[y],r,tmp);
		ans=min(ans,*min_element(tmp+l,tmp+R[x]+1));
	}
	return ans;
}
int main(){
	n=read();
	len=min(330,n);
	blocks=n/len;
	if(n%len)++blocks;
	for(int i=1;i<=blocks;++i){
		L[i]=(i-1)*len+1,R[i]=min(i*len,n);
		for(int j=L[i];j<=R[i];++j)pos[j]=i;
	}
	for(int i=1;i<=n;++i){
		a[i]=b[i]=read();
		p[i]=i;	
	}
	for(int i=1;i<=blocks;++i){
		sort(b+L[i],b+R[i]+1);
		sort(p+L[i],p+R[i]+1,[&](int x,int y){return a[x]<a[y];});
	}
	memcpy(c,b,sizeof(b));
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=blocks;++i){
		for(int j=i+1;j<=blocks;++j){
			static int tmp[N];
			for(int k=L[i];k<=R[i];++k)tmp[k]=inf;
			Merge(L[i],R[i],L[j],R[j],tmp);
			for(int k=L[i];k<=R[i];++k)f[j][p[k]]=tmp[k];
			for(int k=L[i];k<=R[i];++k)f[j][k]=min(f[j][k],f[j-1][k]);
			for(int k=R[i]-1;k>=L[i];--k)f[j][k]=min(f[j][k],f[j][k+1]);	
		}	
	}
	for(int i=blocks;i>=1;--i){
		for(int j=i-1;j>=1;--j){
			static int tmp[N];
			for(int k=L[i];k<=R[i];++k)tmp[k]=inf;
			Merge(L[i],R[i],L[j],R[j],tmp);
			for(int k=L[i];k<=R[i];++k)f[j][p[k]]=tmp[k];
			for(int k=L[i];k<=R[i];++k)f[j][k]=min(f[j][k],f[j+1][k]);	
			for(int k=L[i]+1;k<=R[i];++k)f[j][k]=min(f[j][k],f[j][k-1]);
		}
	}
	for(int i=blocks;i>=1;--i){
		for(int j=L[i]+1;j<=R[i];++j){
			g[i][i]=min(g[i][i],b[j]-b[j-1]);
		}
		for(int j=i+1;j<=blocks;++j){
			g[i][j]=min(min(g[i][j-1],f[i][R[j]]),g[j][j]);
		}
	}
	Q=read();
	while(Q--){
		int l=read(),r=read();
		printf("%d\n",Query(l,r));	
	}
	return 0;
}