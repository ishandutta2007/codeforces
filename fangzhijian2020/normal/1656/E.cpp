#include<bits/stdc++.h>
using namespace std;
const int Mxdt=100000;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
char pc(char c,bool opt){
	return (opt||putchar(c)),0;static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (opt||(*p1++=c,p1==p2))&&(fwrite(buf,1,p1-buf,stdout),p1=buf),0;
}
long long read(){
	long long a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10^48,0);
}
void printnum(int x,char c){
	if(x<0)pc('-',0),x=-x;
	print(x);pc(c,0);
}
int T,n,x,y,h[100005],cnt,v[100005];
struct edge{int to,next;}e[200005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
void dfs(int x,int prt,int dep){
	int i,y,rd=0;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		++rd;dfs(y,x,dep+1);
	}
	if(dep&1)v[x]=rd+(x!=1);
	else v[x]=-(rd+(x!=1));
}
int main(){
	T=read()+1;
	while(--T){
		n=read();for(int i=1;i<=n;++i)h[i]=0;cnt=0;
		for(int i=1;i<n;++i){
			x=read();y=read();
			add(x,y);add(y,x);
		}
		dfs(1,0,0);for(int i=1;i<=n;++i)cout<<v[i]<<" ";puts("");
	}
	return pc(0,1);
}