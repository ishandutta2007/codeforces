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
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
char s[1000002];
int n,f[1000002],a[1000002],m,ans,o,p[1000002],lst[1000002];
int main(){
	scanf("%s",s+1),n=strlen(s+1);s[0]='1';
	for(re int i=0;i<=n;++i)lst[i]=n+1;
	for(re int i=1;i<=n;++i)if(s[i]=='0')p[i]=p[i-1]+1;
	for(re int i=n;i;--i){
		if(s[i]=='1'){
			add(f[i],f[lst[0]]);
			add(f[i],f[lst[1]]);
			add(f[i],1);
		}
		else{
			add(f[i],f[lst[0]]);
			add(f[i],f[lst[p[i]+1]]);
			if(p[i]<=p[n])add(f[i],1);
		}lst[p[i]]=i;
	}
	if(lst[0]==n+1)printf("%d",n);
	else printf("%d",1ll*f[lst[0]]*lst[0]%M);
}