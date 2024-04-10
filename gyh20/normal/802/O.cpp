#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
const int Mxdt=1000000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,m,a[2000002],ans;
char s[2000002];
long long sum;
struct node{
	int x,y;
	bool operator <(const node a)const{return x==a.x?y>a.y:x>a.x;}
};
priority_queue<node>q;
inline bool check(re int x){
	while(!q.empty())q.pop();
	re int ss=0;sum=0;
	for(re int i=1;i<=n&&ss<=m;++i){
		if(s[i]=='('){
			if(a[i]+x<0)q.push((node){a[i],1});
		}
		else{
			if(q.empty())continue;
			re node xx=q.top();
			if(a[i]+xx.x+x>=0)continue;q.pop();
			sum+=a[i]+xx.x+x,ss+=xx.y,q.push((node){-a[i]-x,0});
		}
	}
	return ss<=m;
}
signed main(){
	n=read();n<<=1;m=read();
	for(re int i=1;i<=n;++i)s[i]=(i&1)?'(':')';
	for(re int i=1;i<=n;i+=2)a[i]=read();
	for(re int i=2;i<=n;i+=2)a[i]=read();
	re int l=-1e12,r=1e12;
	while(l<=r){
		re int mid=l+r>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	check(ans);
	printf("%lld",sum-1ll*ans*m);
}