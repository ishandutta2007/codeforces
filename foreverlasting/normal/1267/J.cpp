//minamoto
#include<bits/stdc++.h>
#define R register
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
inline char getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
int read(){
    R int res,f=1;R char ch;
    while((ch=getc())>'9'||ch<'0')(ch=='-')&&(f=-1);
    for(res=ch-'0';(ch=getc())>='0'&&ch<='9';res=res*10+ch-'0');
    return res*f;
}
int read(char *s){
    R int len=0;R char ch;while(((ch=getc())>'9'||ch<'0'));
    for(s[++len]=ch;(ch=getc())>='0'&&ch<='9';s[++len]=ch);
    return s[len+1]='\0',len;
}
double readdb()
{
    R double x=0,y=0.1,f=1;R char ch;
    while((ch=getc())>'9'||ch<'0')(ch=='-')&&(f=-1);
    for(x=ch-'0';(ch=getc())>='0'&&ch<='9';x=x*10+ch-'0');
    for(ch=='.'&&(ch=getc());ch>='0'&&ch<='9';x+=(ch-'0')*y,y*=0.1,ch=getc());
    return x*f;
}
char sr[1<<21],z[20];int C=-1,Z=0;
inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
void print(R int x){
    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
    while(z[++Z]=x%10+48,x/=10);
    while(sr[++C]=z[Z],--Z);sr[++C]='\n';
}
const int P=998244353;
inline void upd(R int &x,R int y){(x+=y)>=P?x-=P:0;}
inline int inc(R int x,R int y){return x+y>=P?x+y-P:x+y;}
inline int dec(R int x,R int y){return x-y<0?x-y+P:x-y;}
inline int mul(R int x,R int y){return 1ll*x*y-1ll*x*y/P*P;}
int ksm(R int x,R int y){
	R int res=1;
	for(;y;y>>=1,x=mul(x,x))(y&1)?res=mul(res,x):0;
	return res;
}
const int N=2e6+5;
int c[N],d[N],p[N],T,n,top;
inline int calc(R int s){
	R int res=0;
	fp(i,1,n)if(c[i])res+=(c[i]+s-1)/s;
	return res;
}
int main(){
	for(scanf("%d",&T);T;--T){
		scanf("%d",&n);memset(c,0,(n+1)<<2),memset(d,0,(n+1)<<2);
		for(R int i=1,x;i<=n;++i)scanf("%d",&x),++c[x];
		fp(i,1,n)if(c[i])++d[c[i]];
		top=0;
		fp(i,1,n)if(d[i])p[++top]=i;
		fd(s,n,1){
			R bool fl=1;
			if(s!=1)fp(i,1,top)if((p[i]+s-1)/s>p[i]/(s-1)){fl=0;break;}
			if(fl){printf("%d\n",calc(s));break;}
		}
	}
	return 0;
}