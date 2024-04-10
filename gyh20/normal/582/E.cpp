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
inline int Mod(re int x){return (x>=M)?x-M:x;}
int N;
inline void FWTor(re int *f){for(re int i=1;i<N;i<<=1)for(re int j=0;j<N;j+=i<<1)for(re int k=0;k<i;++k)add(f[j+k+i],f[j+k]);}
inline void IFWTor(re int *f){for(re int i=1;i<N;i<<=1)for(re int j=0;j<N;j+=i<<1)for(re int k=0;k<i;++k)add(f[j+k+i],M-f[j+k]);}
inline void FWTand(re int *f){for(re int i=1;i<N;i<<=1)for(re int j=0;j<N;j+=i<<1)for(re int k=0;k<i;++k)add(f[j+k],f[j+k+i]);}
inline void IFWTand(re int *f){for(re int i=1;i<N;i<<=1)for(re int j=0;j<N;j+=i<<1)for(re int k=0;k<i;++k)add(f[j+k],M-f[j+k+i]);}
int n,f[502][131072],a[131072],b[131072],m,F[16],ZT;
char s[502];
inline void OR(re int*A,re int*B,re int*C){
	for(re int i=0;i<N;++i)a[i]=A[i],b[i]=B[i];
	FWTor(a),FWTor(b);
	for(re int i=0;i<N;++i)a[i]=1ll*a[i]*b[i]%M;
	IFWTor(a);
	for(re int i=0;i<N;++i)add(C[i],a[i]);
}
inline void AND(re int*A,re int*B,re int*C){
	for(re int i=0;i<N;++i)a[i]=A[i],b[i]=B[i];
	FWTand(a),FWTand(b);
	for(re int i=0;i<N;++i)a[i]=1ll*a[i]*b[i]%M;
	IFWTand(a);
	for(re int i=0;i<N;++i)add(C[i],a[i]);
}
inline void work(re int p,re int c,re int o=2){
	re int zt=0;
	for(re int i=0;i<n;++i)if(F[i]&c)zt|=1<<i;
	if(o^1)++f[p][zt];
	if(o)++f[p][(N-1)^zt];
}
inline int P(re int x){if(x>=97)return 1<<(x-97);return 1<<(x-65);}
inline int C(re int x){if(x>=97)return 1;return 0;}
inline int solve(re int l,re int r){
	if(l==r){
		if(s[l]!='?')work(l,P(s[l]),C(s[l]));
		else work(l,1),work(l,2),work(l,4),work(l,8);
		return l;
	}
	re int pos=0,sum=1;
	for(re int i=l+1;i<=r;++i){
		if(s[i]==')')--sum;
		if(s[i]=='(')++sum;
		if(!sum){
			pos=i+1;
			break;
		}
	}
	re int ls=solve(l+1,pos-2),rs=solve(pos+2,r-1);
	if(s[pos]!='&')OR(f[ls],f[rs],f[pos]);
	if(s[pos]!='|')AND(f[ls],f[rs],f[pos]);
	return pos;
}
int main(){
	scanf("%s",s+1),m=strlen(s+1),n=read(),N=1<<n;
	for(re int i=0;i<n;++i){
		for(re int j=0;j<4;++j)F[i]|=read()<<j;
		ZT|=read()<<i;
	}
	printf("%d",f[solve(1,m)][ZT]);
}