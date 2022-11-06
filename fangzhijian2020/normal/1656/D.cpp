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
long long T,tp;__int128 n,now;
int main(){
	T=read()+1;
//	T=10000000000000;
	while(--T){
		n=now=read();
//		n=now=T;
		if(n&1){
//			if(!opt[2])cout<<";;;\n";
			puts("2");
		}
		else{
			while(now%2==0){
				now/=2;
			}
			if(now==1)puts("-1");
			else{
				if(now*(now+1)/2<=n){
//					if(n%now!=0)puts(";;;;");
					cout<<(tp=now)<<"\n";
				}
				else{
//					if(n%(2*(n/now))!=(n/now))cout<<"::\n";
//					if(2*(n/now)*(2*(n/now)+1)/2>n)puts(":::");
					cout<<(tp=2*(n/now))<<"\n";	
				}
			}
		}
//		puts(":::");
	}
	return pc(0,1);
}