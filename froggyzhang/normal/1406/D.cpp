#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
typedef long long ll;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m;
ll g[N],a[N],B,C;
inline bool check(ll p){
	ll b=a[n]-p,c=a[1]-p;
	if(b>p||c>p)return false;
	if(p+B<b||c+C>p)return false;
	return true;
}
ll calc(){
	ll l=-2e18,r=2e18,ans=0;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			r=mid,ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}
void Change(int u,int x){
	if(g[u]>0)C-=g[u];
	else B-=g[u];
	g[u]+=x;
	if(g[u]>0)C+=g[u];
	else B+=g[u];
}
void Solve_1(){
	m=read();
	printf("%lld\n",a[1]/2);
	for(int i=1;i<=m;++i){
		read(),read(),a[1]+=read();
		printf("%lld\n",a[1]/2);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	if(n==1){
		Solve_1();
		return 0;
	}
	for(int i=1;i<n;++i){
		g[i]=a[i+1]-a[i];
		if(g[i]>0)C+=g[i];
		else B+=g[i];
	}
	printf("%lld\n",calc());
	m=read();
	for(int i=1;i<=m;++i){
		int l=read(),r=read(),x=read();
		if(l==1)a[1]+=x;
		else Change(l-1,x);
		if(r==n)a[n]+=x;
		else Change(r,-x);
		printf("%lld\n",calc());
	}
	return 0;
}