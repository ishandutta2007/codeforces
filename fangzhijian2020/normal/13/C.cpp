#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int Mxdt=100000;const long long INF=1e18;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
long long read(){
	long long a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,x;long long ans=0;
priority_queue<int>q;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		x=read();
		if(!q.empty()&&x<q.top()){
			ans+=q.top()-x;
			q.pop();q.push(x);	
		}q.push(x);
	}
	cout<<ans<<"\n";
	return 0;
}