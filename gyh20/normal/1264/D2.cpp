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
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
int n,m,fac[1000002],inv[1000002],s1[1000002],s2[1000002],s3[1000002],ans,S1[1000002],S2[1000002];
char s[1000002];
inline int C(re int x,re int y){return 1ll*fac[x]*inv[y]%M*inv[x-y]%M;}
inline int calc(re int x,re int y){
	re int s=(y==s2[n])?S1[y]:S2[y];
	if(-x>y)return 0;
	if(x<0)add(s,M-(y==s2[n]?S1[-x-1]:S2[-x-1]));
	return s;
}
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	for(re int i=fac[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M;inv[n]=ksm(fac[n],M-2);
	for(re int i=n-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M; 
	for(re int i=1;i<=n;++i)s1[i]=s1[i-1]+(s[i]=='('),s2[i]=s2[i-1]+(s[i]=='?'),s3[i]=s3[i-1]+(s[i]==')');
	for(re int i=0;i<=s2[n];++i)S1[i]=C(s2[n],i);
	for(re int i=0;i<s2[n];++i)S2[i]=C(s2[n]-1,i);
	for(re int i=1;i<=s2[n];++i)add(S1[i],S1[i-1]);
	for(re int i=1;i<s2[n];++i)add(S2[i],S2[i-1]);
	for(re int i=1;i<=n;++i)if(s[i]!=')')add(ans,calc(s3[n]-s3[i]-s1[i-1]-1-s2[i-1],s2[i-1]+s2[n]-s2[i]));
	printf("%d",ans);
}