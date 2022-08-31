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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int f[1002][1002][3],ans,g[1002][1002][3];
char s[1002],t[1002];
int n,m;
signed main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(re int i=0;i<=n;++i){
		re int x=i,ss=1;
		while(x>1&&(s[x]^s[x-1]))--x,++ss;
		f[i][0][1]=ss;
	}
	for(re int i=0;i<=m;++i){
		re int x=i,ss=1;
		while(x>1&&(t[x]^t[x-1]))--x,++ss;
		f[0][i][2]=ss;
	}
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<=m;++j){
		//	if(s[i]^t[j])f[i][j][1]=f[i][j][2]=1;
			if(s[i]^s[i-1])add(f[i][j][1],f[i-1][j][1]);
			if(s[i]^t[j])add(f[i][j][1],f[i-1][j][2]);
			if(t[j]^t[j-1])add(f[i][j][2],f[i][j-1][2]);
			if(t[j]^s[i])add(f[i][j][2],f[i][j-1][1]);
			add(f[i][j][1],1),add(f[i][j][2],1);
			add(ans,f[i][j][1]),add(ans,M-f[i][0][1]),add(ans,f[i][j][2]),add(ans,M-f[0][j][2]);
		}
	}
	printf("%d",ans);
}