#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=5e5+10;
const int mo=998244353;
const ll inf=1e18;
ll a[N*4];int lz[N*4];char s[N];
void f(int x,int y,int z,int L,int R){
	if(L==R){
		a[x]=z;return;
	}
	int m=(L+R)>>1;
	if(y<=m)f(x<<1,y,z-lz[x],L,m);
	else f(x<<1|1,y,z-lz[x],m+1,R);
	a[x]=a[x<<1]+a[x<<1|1]+1ll*lz[x]*(R-L+1);
}
void ad(int x,int l,int r,int L,int R){
	if(l<=L&&r>=R){
		a[x]+=R-L+1;++lz[x];return;
	}
	int m=(L+R)>>1;
	if(l<=m)ad(x<<1,l,r,L,m);
	if(r>m)ad(x<<1|1,l,r,m+1,R);
	a[x]=a[x<<1]+a[x<<1|1]+1ll*lz[x]*(R-L+1);
}
int main(){int n;
	scanf("%d%s",&n,s+1);
	int cnt=0;ll ans=0;
	rep(i,1,n){
		if(s[i]=='1'){++cnt;
			f(1,cnt,i-cnt+1,1,n);
			if(cnt>1)ad(1,1,cnt-1,1,n);
		}else cnt=0;
		ans+=a[1];
	}
	printf("%lld\n",ans);
}