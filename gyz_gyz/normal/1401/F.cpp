#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=1e9+7;
ll a[N*4];bool re[20],sw[20];
void bd(int x,int l,int r){
	if(l==r){
		scanf("%lld",&a[x]);return;
	}
	int m=(l+r)>>1;
	bd(x*2,l,m);bd(x*2+1,m+1,r);
	a[x]=a[x*2]+a[x*2+1];
}
void f(int x,int y,ll z,int h,int L,int R){
	if(L==R){
		a[x]=z;return;
	}
	int m=(L+R)>>1;
	if(y<=m)f(x*2+(re[h]^sw[h-1]),y,z,h-1,L,m);
	else f(x*2+(re[h]^sw[h-1]^1),y,z,h-1,m+1,R);
	a[x]=a[x*2]+a[x*2+1];
}
ll q(int x,int l,int r,int h,int L,int R){
	if(l<=L&&r>=R)return a[x];
	int m=(L+R)>>1;
	return (l<=m?q(x*2+(re[h]^sw[h-1]),l,r,h-1,L,m):0)
	+(r>m?q(x*2+(re[h]^sw[h-1]^1),l,r,h-1,m+1,R):0);
}
int main(){int n,m;
	scanf("%d%d",&n,&m);
	bd(1,1,1<<n);
	rep(i,1,m){int op;
		scanf("%d",&op);
		if(op==1){int x;ll y;
			scanf("%d%lld",&x,&y);
			f(1,x,y,n,1,1<<n);
		}
		if(op==2){int x;
			scanf("%d",&x);
			rep(j,0,x)re[j]^=1;
		}
		if(op==3){int x;
			scanf("%d",&x);
			sw[x]^=1;
		}
		if(op==4){int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",q(1,l,r,n,1,1<<n));
		}
	}
}