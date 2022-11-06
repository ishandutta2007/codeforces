#include<bits/stdc++.h>
using namespace std;
const int Mxdt=100000;const long long INF=1e18;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
char pc(char c,bool opt){
	return (opt||putchar(c)),0;static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (opt||(*p1=++c,p1==p2))&&(fwrite(buf,1,p1-buf,stdout),p1=buf),0;
}
int read(){
	int a=0;bool opt=0;char c=gc();
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
int n,h[300005],b[300005],st[300005],top;
long long f[300005],mx[300005],Max[300005];
int main(){
	n=read();
	for(int i=1;i<=n;++i)h[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	Max[0]=-INF;
	for(int i=1;i<=n;++i){
		long long now=f[i-1];
		while(top&&h[st[top]]>h[i]){
			now=max(now,mx[top]);--top;
		}
		st[++top]=i;mx[top]=now;
		Max[top]=max(Max[top-1],mx[top]+b[i]);
		f[i]=Max[top];
	}
	cout<<f[n]<<'\n';
	return pc(0,1);
}