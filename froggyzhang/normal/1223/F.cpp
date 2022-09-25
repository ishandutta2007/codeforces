#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define N 300030
typedef unsigned long long ull;
const ull base=1145141;
inline ll read(){
	ll x=0,f=1;
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
int T,n,a[N];
ll ans;
void calc(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	calc(l,mid),calc(mid+1,r);
	static int st[N],top;
	static ull h[N];
	top=0;
	gp_hash_table<ull,int> mp;
	for(int i=mid;i>=l;--i){
		if(top&&a[i]==st[top])--top;
		else st[++top]=a[i],h[top]=h[top-1]*base+a[i];
		++mp[h[top]];
	}
	top=0;
	for(int i=mid+1;i<=r;++i){
		if(top&&a[i]==st[top])--top;
		else st[++top]=a[i],h[top]=h[top-1]*base+a[i];
		if(mp.find(h[top])!=mp.end())ans+=mp[h[top]];
	}
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	ans=0;calc(1,n);
	printf("%lld\n",ans);
}
int main(){
	T=read();
	while(T--)Solve();
	return 0;
}