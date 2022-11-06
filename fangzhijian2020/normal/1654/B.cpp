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
int T,len,h[505];char c[200005];
int main(){
	T=read()+1;
	while(--T){
		scanf("%s",c+1);len=strlen(c+1);
		for(int i=1;i<=len;++i)++h[c[i]];
		int now=1;
		while(h[c[now]]>1){
			--h[c[now]];++now;
		}
		for(int i=now;i<=len;++i){
			putchar(c[i]);
		}
		puts("");
		for(int i=1;i<=len;++i)h[c[i]]=0;
	}
	return pc(0,1);
}