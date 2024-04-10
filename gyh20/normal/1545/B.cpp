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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[2][100002],b[2][100002],m1,m2;
char s[100002];
int main(){
	t=read();
	while(t--){
		n=read(),scanf("%s",s+1),m1=0,m2=0;
		for(re int i=1;i<=n;++i){
			if(s[i]=='1'){
				if(s[i+1]=='1')++m2,++i,++m1;
			}
			else ++m1;
		}
		re int s=1;
		for(re int i=m1-m2+1;i<=m1;++i)s=1ll*s*i%M;
		for(re int i=1;i<=m2;++i)s=1ll*s*ksm(i,M-2)%M;
		printf("%d\n",s);
	}
}