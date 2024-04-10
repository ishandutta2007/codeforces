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
int t,n,m,a[1000002],ans,cnt,head[1000002],lst;
char s[200002];
signed main(){
	t=read();
	while(t--){
		scanf("%s",s+1);
		lst=0;
		re int ia=1;
		n=strlen(s+1);
		for(re int i=n;i;--i){
			re int j=i;
			while(s[j-1]==s[i])--j;
			if(j==i)continue;
			i=j;
			if(s[i]=='1'&&lst)ia=0;
			else if(s[i]=='0')lst=1;
		}
		puts(ia?"YES":"NO");
	}
}