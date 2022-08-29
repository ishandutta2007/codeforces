#include<cstdio>
#define re register
using namespace std;
const int Mxdt=300000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,a[300002],b[300002],c[300002],val[300002],m,s[300002];
char st[300002];
int main(){
	n=read(),m=read();
	for(re int i=1;i<=m;++i){
		a[i]=read(),b[i]=read(),c[i]=read();s[a[i]]+=c[i],s[b[i]]+=c[i];
		if(val[a[i]]<val[b[i]])val[a[i]]+=c[i],val[b[i]]-=c[i],st[i]=1;
		else val[a[i]]-=c[i],val[b[i]]+=c[i];
	}
	for(re int ii=1;ii<=7;++ii){
		for(re int i=1;i<=m;++i){
			if(st[i]&&(((s[a[i]]&1)&&val[a[i]]>1)||((s[b[i]]&1)&&val[b[i]]<-1)))val[a[i]]-=c[i]<<1,val[b[i]]+=c[i]<<1,st[i]=0;
			else if(!st[i]&&(((s[a[i]]&1)&&val[a[i]]<-1)||((s[b[i]]&1)&&val[b[i]]>1)))val[a[i]]+=c[i]<<1,val[b[i]]-=c[i]<<1,st[i]=1;
		}
	}
	re int s=0;
	for(re int i=1;i<=n;++i)s+=val[i]==1||val[i]==-1;
	printf("%d\n",s);
	for(re int i=1;i<=m;++i)st[i]+='1';
	puts(st+1);
}