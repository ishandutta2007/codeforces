#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000,N=2000000;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,a[1000005],h[2000005],p[2000005],ans=0,q[2000005],top,s[2000005];
void add(int s,int x){
	q[++top]=s;
	if(x&1){
		h[s]=min(h[s],x);
	}
	else{
		p[s]=min(p[s],x);
	}
}
void del(){
	while(top){
		h[q[top]]=n+1;
		p[q[top]]=n+1;
		--top;
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=0;i<=N;++i)h[i]=p[i]=n+1;p[0]=0;
	for(int t=0;t<20;++t){
		p[0]=0;q[top=1]=0;
		for(int i=1;i<=n;++i){
			s[i]=s[i-1]^a[i];
			if(!((a[i]>>t)&1))del();
			else{
				if(i&1){
					ans=max(ans,i-h[s[i]>>t+1]);
				}
				else{
					ans=max(ans,i-p[s[i]>>t+1]);
				}
				add(s[i-1]>>t+1,i-1);
			}
		}
		del();
	}
	cout<<ans<<"\n";
	return 0;
}