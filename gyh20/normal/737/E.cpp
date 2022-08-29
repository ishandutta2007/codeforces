#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,X,p[22],S[42],T[42],a[42],sum[42],G[62][62],ans,Sum,my[62];
char v[62],oo[12],E[62][62];
inline int dfs(re int x){
	for(re int i=1;i<=m+m+n;++i)
		if(E[x][i]&&!v[i]){
			v[i]=1;
			if(!my[i]||dfs(my[i])){my[i]=x;return 1;}
		}return 0;
}
inline bool cmp(re int x,re int y){return T[x]>T[y];}
int main(){
	n=read(),m=read(),X=read();
	for(re int i=1;i<=m;++i)p[i]=read(),a[i]=i;
	for(re int i=1;i<=n;++i){
		re int k=read();
		while(k--){
			re int x=read(),y=read();
			S[i]+=y,T[x]+=y,G[i][x]=y;
			Sum+=y; 
		}
	}
	sort(a+1,a+m+1,cmp);
	for(re int i=1;i<=m;++i){
		re int x=a[i];
		if(X>=p[x])T[x+m]=T[x]>>1,T[x]=T[x]+1>>1,X-=p[x],oo[x]=1;
	}
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j){
			sum[j]+=G[i][j];
			if(sum[j]>T[j]){
				G[i][j]-=sum[j]-T[j];
				G[i][j+m]+=sum[j]-T[j];
				sum[j]=T[j];
			}
		}
	for(re int i=1;i<=n;++i)ans=max(ans,S[i]);
	for(re int i=1;i<=m+m;++i)ans=max(ans,T[i]);
	printf("%d\n",ans);
	for(re int i=1;i<=m;++i)putchar(oo[i]+'0');
	puts("");
	printf("%d\n",Sum);
	for(re int i=1;i<=n;++i)G[i][i+m+m]=ans-S[i];
	for(re int i=1;i<=m+m;++i)G[i+n][i]=ans-T[i];
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m+m;++j)
			G[j+n][i+m+m]=G[i][j];
	for(re int i=1;i<=ans;++i){
		memset(E,0,sizeof(E)),memset(my,0,sizeof(my));
		for(re int j=1;j<=n+m+m;++j)for(re int k=1;k<=n+m+m;++k)if(G[j][k])E[j][k]=1;
		for(re int j=1;j<=n+m+m;++j)memset(v,0,sizeof(v)),dfs(j);
		for(re int j=1;j<=m+m+n;++j){
			if(my[j]){
				--G[my[j]][j];
				if(j<=m+m&&my[j]<=n)printf("%d %d %d %d\n",my[j],j<=m?j:j-m,i-1,1);
			}
		}
	}
}