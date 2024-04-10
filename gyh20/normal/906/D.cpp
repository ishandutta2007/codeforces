#include<bits/stdc++.h>
#define re register
#define ui unsigned int
#define ull unsigned long long
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(int x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch)
{
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,a[100002],phi[102],tot,M[102],k,f[100002];
struct Fast_Mod {	ui M,a,b;	inline Fast_Mod(const ui m=2):M(m),a((1ull<<32)/m),b(((1ull<<32)%m<<32)/m){}	inline ull Mo(ull x) const {		return x-=((((x&~0u)*a+(x>>32)*b)>>32)+(x>>32)*a)*M,x>=M?x-M:x;	}}F[102];
inline int Mod(re long long x,re int o){return x<M[o]?x:(F[o].Mo(x)+M[o]);}
inline int ksm(re int x,re int y,re int o){
	re int s=1;
	while(y){
		if(y&1)s=Mod(1ll*s*x,o);
		x=Mod(1ll*x*x,o),y>>=1;
	}
	return s;
}
inline int PHI(re int x){
	if(x==1)return 0;
	re long long sum=x;
	for(re int i=2;i*i<=x;++i)
		if(x%i==0){
			sum*=(i-1),sum/=i;
			while(!(x%i))x/=i;
		}
	if(x>1)sum*=(x-1),sum/=x;
	return sum;
}
signed main(){
	n=read();re int MOD=read(),MM=MOD;
	while(MOD)M[++tot]=MOD,F[tot]=Fast_Mod(MOD),MOD=PHI(MOD);
	for(re int i=1;i<=n;++i)a[i]=read();
	re int q=read();
	while(q--){
		re int l=read(),r=read(),s=Mod(a[r],min(r-l+1,tot));
		if(r-l+1>=tot){
			if(!f[l]){
				for(re int i=min(r-l+1,tot)-1;i;--i)s=ksm(a[i+l-1],s,i);
				f[l]=s;	
			}
			else s=f[l];
		}
		else for(re int i=min(r-l+1,tot)-1;i;--i)s=ksm(a[i+l-1],s,i);
		printnum(s%MM,'\n');
	}pc('o',1);
}