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
int T,n,k,x,opt1,opt2,opts;map<int,int>mp;
int main(){
	T=read()+1;
	while(--T){
		n=read();opt1=opt2=opts=0;mp.clear();
		for(int i=1;i<=n;++i){
			x=read();if(mp.find(x-1)!=mp.end()||mp.find(x+1)!=mp.end())opts=1;
			if(x==0)opt1=1;
			if(x==1)opt2=1;mp[x]=1;
		}
		if(opt1&&opt2)puts("NO");
		else{
			if(!opt2)puts("YES");
			else{
				if(opts)puts("NO");
				else puts("YES");
			}
		}
	}
	return pc(0,1);
}