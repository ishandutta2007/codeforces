#include<bits/stdc++.h>
#define re register
using namespace std;
#define int long long
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
struct node{
	int x,y,z;
	bool operator <(const node a)const{return z<a.z;}
}p[100002];
int t,n,m,a[102][102],head[1000002],b[1000002],num,k,ans[102][102],v[102][102];
char s[1000002]; 
signed main(){
	t=read();
	while(t--){
		n=read(),m=read(),k=0;
		for(re int i=1;i<=n;++i){
			for(re int j=1;j<=m;++j){
				a[i][j]=read(),v[i][j]=ans[i][j]=0;
				p[++k]=(node){i,j,a[i][j]};
			}
		}
		sort(p+1,p+k+1),num=0;
		for(re int i=1;i<=m;++i)v[p[i].x][p[i].y]=1;
		for(re int i=1;i<=n;++i){
			for(re int j=1;j<=m;++j)if(v[i][j])ans[i][++num]=a[i][j];
			re int pos=1;
			for(re int j=1;j<=m;++j){
				if(ans[i][j])continue;
				while(v[i][pos])++pos;
				ans[i][j]=a[i][pos],++pos;
			}
		}
		for(re int i=1;i<=n;++i,puts(""))for(re int j=1;j<=m;++j)printf("%lld ",ans[i][j]);
		
		
	}
}