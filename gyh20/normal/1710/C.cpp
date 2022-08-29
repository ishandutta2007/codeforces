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
int t,n,m,a[1000002],ans,A,B,f[200002][2][2][2][2][2][2];
char s[1000002];
inline int ask(re int pos,re int a1,re int a2,re int a3,re int a4,re int a5,re int a6){
	if(pos==n+1)return a4&&a5&&a6;
	if(~f[pos][a1][a2][a3][a4][a5][a6])return f[pos][a1][a2][a3][a4][a5][a6];
	re int&ss=f[pos][a1][a2][a3][a4][a5][a6];ss=0;
	for(re int i=0;i<=(a1?s[pos]:1);++i)
		for(re int j=0;j<=(a2?s[pos]:1);++j)
			for(re int k=0;k<=(a3?s[pos]:1);++k){
				if(i==j&&j==k)add(ss,ask(pos+1,a1&(i==s[pos]),a2&(j==s[pos]),a3&(k==s[pos]),a4,a5,a6));
				else{
					re int n4=a4,n5=a5,n6=a6;
					if(i!=j&&i!=k)n4=1;
					if(j!=i&&j!=k)n5=1;
					if(k!=i&&k!=j)n6=1;
					add(ss,ask(pos+1,a1&(i==s[pos]),a2&(j==s[pos]),a3&(k==s[pos]),n4,n5,n6));
				}
			}
	return ss;
}
int main(){
	scanf("%s",s+1),memset(f,-1,sizeof(f)),n=strlen(s+1);
	for(re int i=1;i<=n;++i)s[i]-='0';
	printf("%d",ask(1,1,1,1,0,0,0));
}