#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,ans,a[200005],b[200005],t[800005];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
void pushup(int k){
	t[k]=gcd(t[k<<1],t[k<<1|1]);
}
void build(int k,int l,int r){
	if(l==r){t[k]=b[l];return;}
	int mid=l+r>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
}
int query(int k,int l,int r,int L,int R){
	if(L<=l&&r<=R)return t[k];
	int mid=l+r>>1,ans=0;
	if(L<=mid)ans=gcd(ans,query(k<<1,l,mid,L,R));
	if(R>mid)ans=gcd(ans,query(k<<1|1,mid+1,r,L,R));
	return ans;
}
bool check(int l,int r){
	if(l==r)return 1;
	return query(1,1,n-1,l,r-1)>1;
}
signed main(){
	T=read()+1;
	while(--T){
		n=read();ans=0;
		for(int i=1;i<=n;++i)a[i]=read();
		if(n==1){puts("1");continue;}
		for(int i=1;i<n;++i)b[i]=abs(a[i+1]-a[i]);
		build(1,1,n-1);
		for(int i=1,j=1;i<=n;++i){
			while(j<=n&&check(i,j))++j;
			ans=max(ans,j-i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}