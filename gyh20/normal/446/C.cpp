#include<bits/stdc++.h>
#define re register
using namespace std;
const int M=1e9+9;
const int Mxdt=1000000;
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
inline int Mod(re int x){return x>=M?x-M:x;}
inline void add(re int &x,re int y){x=Mod(x+y);}
int n,m,a[300003],b[300003],tp,tg[300003],f[300003],k,g[300003],sum[300003];
int main(){
	n=read(),m=read(),f[1]=g[1]=1;
	for(re int i=2;i<=n;++i)f[i]=Mod(f[i-2]+f[i-1]),g[i]=f[i],add(g[i],g[i-1]);
	for(re int i=1;i<=n;++i)sum[i]=Mod(sum[i-1]+read());
	k=700;
	while(m--){
		re int o=read(),l=read(),r=read();
		if(o==1)a[++tp]=l,b[tp]=r,++tg[l],add(tg[r+1],M-f[r-l+2]),add(tg[r+2],M-f[r-l+1]);
		else{
			if(tp>=k){
				re int S=tg[1];
				add(sum[1],tg[1]);
				for(re int i=2;i<=n;++i)add(tg[i],Mod(tg[i-1]+tg[i-2])),add(S,tg[i]),add(sum[i],S);
				memset(tg,0,sizeof(tg));
				tp=0;
			}
			re int ans=Mod(sum[r]-sum[l-1]+M);
			for(re int i=1;i<=tp;++i){
				re int y=min(b[i],r),x=max(a[i],l);
				if(x>y)continue;
				add(ans,Mod(g[y-a[i]+1]-g[x-a[i]]+M));
			}
			printnum(ans,'\n');
		}
	}
	pc('o',1);
}