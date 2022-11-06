#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
const int M=6e6+10;
const int mo=998244353;
struct E{ll x,y;
	friend bool operator <(const E&a,const E&b){
		return atan2(a.x,a.y)+1e-15<atan2(b.x,b.y);
	}
};
int a[M],ls[M],rs[M],rt[N],tot;queue<int>t[N];
void bd(int x,int fx,queue<int>&t,int l,int r){
	if(l==r){
		for(a[x]=a[fx];!t.empty()&&t.front()==l;t.pop())++a[x];return;
	}int m=(l+r)>>1;
	if(!t.empty()&&t.front()<=m){
		ls[x]=++tot;bd(ls[x],ls[fx],t,l,m);
	}else ls[x]=ls[fx];
	if(!t.empty()&&t.front()<=r){
		rs[x]=++tot;bd(rs[x],rs[fx],t,m+1,r);
	}else rs[x]=rs[fx];
	a[x]=a[ls[x]]+a[rs[x]];
}
int q(int x,int l,int r,int L,int R){
	if(!x)return 0;
	if(l<=L&&r>=R)return a[x];int m=(L+R)>>1;
	return (l<=m?q(ls[x],l,r,L,m):0)+(r>m?q(rs[x],l,r,m+1,R):0);
}
int main(){int n;
	scanf("%d",&n);map<E,int>mp;
	rep(i,1,n){ll x0,y0,lx,ly,x,y;int k;
		scanf("%d%lld%lld",&k,&x0,&y0);x=x0;y=y0;
		rep(j,2,k){lx=x;ly=y;
			scanf("%lld%lld",&x,&y);
			E e={x-lx,y-ly};
			t[mp[e]].push(i);mp[e]=i;
		}
		E e={x0-x,y0-y};
		t[mp[e]].push(i);mp[e]=i;
	}
	rep(i,0,n-1){rt[i]=++tot;
		bd(rt[i],i?rt[i-1]:0,t[i],1,n);
	}
	int m;scanf("%d",&m);
	rep(i,1,m){int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",q(rt[l-1],l,r,1,n));
	}
}