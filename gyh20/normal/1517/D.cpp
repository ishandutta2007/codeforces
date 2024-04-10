#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
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
	if(x<0)pc('-',false),x=-x;
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
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
int t,n,m,k,a[502][502],b[502][502],mn[502][502],dis[502][502];
inline void gmn(re int &x,re int y){y<x&&(x=y);}
signed main(){
	n=read(),m=read(),k=read();
	for(re int i=1;i<=n;++i)for(re int j=1;j<m;++j)a[i][j]=read();
	for(re int i=1;i<n;++i)for(re int j=1;j<=m;++j)b[i][j]=read();
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j){
			mn[i][j]=1e9;
			if(j^m)mn[i][j]=min(mn[i][j],a[i][j]);
			if(j^1)mn[i][j]=min(mn[i][j],a[i][j-1]);
			if(i^n)mn[i][j]=min(mn[i][j],b[i][j]);
			if(i^1)mn[i][j]=min(mn[i][j],b[i-1][j]);
		}
	const int inf=2e9;
	for(re int i=1;i<=n;++i,pc('\n',0)){
		for(re int j=1;j<=m;++j){
			if(k&1){printnum(-1,' ');continue;}
			re int lx=max(1,i-10),rx=min(n,i+10),ly=max(1,j-10),ry=min(m,j+10);
			for(re int ii=lx;ii<=rx;++ii)
				for(re int jj=ly;jj<=ry;++jj)
					dis[ii][jj]=inf;
			dis[i][j]=0;
			re int ans=k*mn[i][j];
			for(re int o=1;o<=(k>>1)-1;++o){
				re int lx=max(1,i-o),rx=min(n,i+o),ly=max(1,j-o),ry=min(m,j+o);
				for(re int ii=lx;ii<=rx;++ii)
					for(re int jj=ly+(((abs(i-ii)+abs(j-ly))&1)^(o&1));jj<=ry;jj+=2){
						dis[ii][jj]=2e9;
						if(ii^lx)gmn(dis[ii][jj],dis[ii-1][jj]+b[ii-1][jj]);
						if(ii^rx)gmn(dis[ii][jj],dis[ii+1][jj]+b[ii][jj]);
						if(jj^ly)gmn(dis[ii][jj],dis[ii][jj-1]+a[ii][jj-1]);
						if(jj^ry)gmn(dis[ii][jj],dis[ii][jj+1]+a[ii][jj]);
						if(dis[ii][jj]<inf)gmn(ans,dis[ii][jj]*2+(k-o*2)*mn[ii][jj]);
					}
			}
			printnum(ans,' ');
		}
	}
	pc('o',1);
}