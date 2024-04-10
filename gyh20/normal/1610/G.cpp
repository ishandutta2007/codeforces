#include<bits/stdc++.h>
#define re register
#define ui unsigned int
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,f[300002],L[300002],fa[22][300002],R[300002],stk[300002],tp,F[300002];
ui hsh[22][300002],pw[300002],B=131;
char s[300002];
inline int root(re int x){return x==F[x]?x:F[x]=root(F[x]);}
inline bool cmp(re int x,re int y){
	x=root(x),y=root(y);
	for(re int i=20;~i;--i)if(hsh[i][x]==hsh[i][y])x=fa[i][x],y=fa[i][y];
	return s[x]<s[y];
}
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	for(re int i=n;i;--i)
		if(s[i]==')')stk[++tp]=i;
		else R[i]=stk[tp--],tp=max(tp,0);
	for(re int i=pw[0]=1;i<=n;++i)pw[i]=pw[i-1]*B,F[i]=i;F[n+1]=n+1;
	for(re int i=n;~i;--i){
		fa[0][i]=root(i+1);
		if(R[i+1]&&cmp(R[i+1]+1,i+1))fa[0][i]=root(R[i+1]+1);
		hsh[0][i]=s[i];
		for(re int j=1;j<=20;++j)fa[j][i]=fa[j-1][fa[j-1][i]],hsh[j][i]=hsh[j-1][i]+hsh[j-1][fa[j-1][i]]*pw[1<<j-1];
		if(R[i]&&cmp(R[i]+1,i))F[i]=root(R[i]+1);
	}
	re int pos=fa[0][0];
	while(pos<=n)putchar(s[pos]),pos=fa[0][pos];
}