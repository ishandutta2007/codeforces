#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=200005;
typedef long long ll;
ll a[N],b[N],c[N],d[N];
int ans;
void solve(int l,int r){
	if(l==r){
		if(b[l]>1)chmax(ans,1);
		return;
	}
	int mid=(l+r)>>1;
	ll g=0;for(int i=mid;i>=l;--i)c[i]=g=gcd(g,b[i]);
	g=0;for(int i=mid+1;i<=r;++i)d[i]=g=gcd(g,b[i]);
	int cur=mid;
	for(int i=l;i<=mid;++i){
		while(cur+1<=r&&gcd(c[i],d[cur+1])>1)++cur;
		if(cur>mid)chmax(ans,cur-i+1);
	}
	solve(l,mid),solve(mid+1,r);
}
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	if(n==1)return puts("1"),void();
	for(int i=1;i<n;++i)b[i]=abs(a[i]-a[i+1]);
	ans=0,solve(1,n-1);
	printf("%d\n",ans+1);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}