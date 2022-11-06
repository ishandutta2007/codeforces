#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=3e5+10;
const int inf=1e9;
int s[N];
struct pr{
	int a[19];
	pr(){rep(i,0,18)a[i]=1<<i;}
	friend pr operator+(const pr&a,const pr&b){pr c=a;
		rep(i,0,18){
			c.a[i]|=b.a[i];
			if(c.a[i]^((1<<19)-1))
			    rep(j,0,18)if((a.a[i]>>j)&1)c.a[i]|=b.a[j];
		}
		return c;
	}
}a[N*4];
void build(int x,int l,int r){
	if(l==r){
		rep(i,0,18)if((s[l]>>i)&1)a[x].a[i]=s[l];return;
	}int m=(l+r)>>1;
	build(x<<1,l,m);build(x<<1|1,m+1,r);
	a[x]=a[x<<1]+a[x<<1|1];
}
pr q(int x,int l,int r,int L,int R){
	if(l==L&&r==R)return a[x];
	int m=(L+R)>>1;
	if(r<=m)return q(x<<1,l,r,L,m);
	if(l>m)return q(x<<1|1,l,r,m+1,R);
	pr res=q(x<<1,l,m,L,m)+q(x<<1|1,m+1,r,m+1,R);
	return res;
}
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&s[i]);
	build(1,1,n);
	rep(i,1,m){int l,r;
		scanf("%d%d",&l,&r);
		pr t=q(1,l,r-1,1,n);int x=0;
		rep(j,0,18)if((s[l]>>j)&1)x|=t.a[j];
		if(x&s[r])printf("Shi\n");else printf("Fou\n");
	}
}