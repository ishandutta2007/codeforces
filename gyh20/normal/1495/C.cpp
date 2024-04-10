#include<bits/stdc++.h>
#define re register
//#define int long long
const int M=1e9+7;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[1000002],b[1000002],head[1000002],cnt,A,B,C,D;
struct edge{int to,next;}e[2000002];
inline void addd(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
char s[502][502],ans[502][502];
#define Y puts("YES");
#define N puts("NO");
signed main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<=n;++i)scanf("%s",s[i]+1);
		for(re int i=1;i<=n+1;i++)for(re int j=1;j<=m+1;++j)ans[i][j]=0;
		for(re int i=1;i<=n;++i)for(re int j=1;j<=m;++j)ans[i][j]=s[i][j];
		for(re int i=1;i<=n;i+=3)for(re int j=1;j<=m;++j)ans[i][j]='X';
		for(re int i=1;i<=n;i+=3){
			re int fst=0,tmp=0;
			if(i+2==n){
				for(re int j=1;j<=m;++j)if(ans[i+2][j]=='X')ans[i+1][j]='X';
				break;
			}
			if(i+1==n||i==n)break;
			for(re int j=1;j<=m;++j)
				if(s[i+2][j]=='X'){
					fst=1;
					ans[i+1][j]='X';
					break;
				}
			if(!fst){
			for(re int j=1;j<=m;++j)
				if(s[i+1][j]=='X'){
					fst=1;
					ans[i+2][j]='X';
					break;
				}
			}
			if(!fst){
				ans[i+1][1]=ans[i+2][1]='X';
			}
		}
		for(re int i=1;i<=n;++i)printf("%s\n",ans[i]+1);
	}
}