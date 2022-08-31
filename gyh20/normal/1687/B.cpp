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
int t,n,m,a[1000002],ans,A,B,p[502],len[502],lst;
char s[1000002];
inline bool cmp(re int x,re int y){
	return len[x]<len[y];
}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=m;++i)s[i]='0';
	for(re int i=1;i<=m;++i){p[i]=i;
		s[i]='1';
		printf("? %s\n",s+1);
		fflush(stdout);
		len[i]=read();
		s[i]='0';
	}
	sort(p+1,p+m+1,cmp);
	for(re int i=1;i<=m;++i){
		re int x=p[i];
		s[x]='1';
		printf("? %s\n",s+1);
		fflush(stdout);
		ans=read();
		if(ans!=lst+len[x])s[x]='0';
		else lst=ans; 
	}
	printf("! %d",lst);fflush(stdout);
}