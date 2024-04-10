#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int n,m,lst[2002],d[2002],k;
char s[1002][1002],ans[1002][1002];
inline bool ck(re int x,re int y){
	if(s[x][y]=='0')return 0;
	re int z=y-x+1000;
	if(d[z]==0)return 0;
	if(x==y){
		if(lst[z-1]>=lst[z]&&lst[z+1]>=lst[z])return 1;
		return 0;
	}
	if(x<y){
		if(lst[z]>=lst[z-1])return 0;
		if(lst[z]>lst[z+1])return 0;
		return 1;
	}
	if(x>y){
		if(lst[z]>=lst[z+1])return 0;
		if(lst[z]>lst[z-1])return 0;
		return 1;
	}
} 
int main(){
	int t=read();
	while(t--){
		n=read(),m=read();m=n-m+1;
		for(re int i=1;i<=n;++i)scanf("%s",s[i]+1);
		for(re int i=1;i<=n;++i)for(re int j=1;j<=n;++j)ans[i][j]=0;
		memset(lst,0,sizeof(lst)),memset(d,0,sizeof(d));
		for(re int i=1;i<=m;++i)d[i-1+1000]=d[1-i+1000]=m-i+1;
		for(re int i=1;i<=n;++i){
			for(re int j=i;j<=min(i+m-1,n);++j)
				if(ck(i,j))--d[j-i+1000],ans[i][j]=1,lst[j-i+1000]=i;
			for(re int j=i+1;j<=min(i+m-1,n);++j)
				if(ck(j,i))--d[i-j+1000],ans[j][i]=1,lst[i-j+1000]=i;
		}
		re bool ia=1;
		for(re int i=1;i<=m;++i)ia&=d[i-1+1000]==0,ia&=d[1-i+1000]==0;
		puts(ia?"YES":"NO");
		if(ia){
			for(re int i=1;i<=n;++i,puts(""))
				for(re int j=1;j<=n;++j)
					printf("%d",ans[i][j]^1);
		}
		
	}
}