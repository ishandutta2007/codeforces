#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
int n,m,f[3002][3002];
char s[3002][3002];
inline int calc(re int X1,re int Y1,re int X2,re int Y2){
	if(s[X1][Y1]=='#')return 0;
	memset(f,0,sizeof(f)),f[X1][Y1]=1;
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j)
			if(f[i][j]){
				if(s[i][j+1]!='#')add(f[i][j+1],f[i][j]);
				if(s[i+1][j]!='#')add(f[i+1][j],f[i][j]);
			}
	return f[X2][Y2];
}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)scanf("%s",s[i]+1);
	printf("%d",(1ll*calc(1,2,n-1,m)*calc(2,1,n,m-1)+1ll*(M-calc(2,1,n-1,m))*calc(1,2,n,m-1))%M);
}