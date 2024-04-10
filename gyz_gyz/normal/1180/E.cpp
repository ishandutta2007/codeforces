#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e6+10;
const int mo=998244353;
int a[N],b[N],s[N],lz[N];
void f(int x,int L,int R,int y,int l,int r){
	if(L<=l&&R>=r){
		s[x]+=y;lz[x]+=y;return;
	}int m=(l+r)>>1;
	if(L<=m)f(x<<1,L,R,y,l,m);
	if(R>m)f(x<<1|1,L,R,y,m+1,r);
	s[x]=max(s[x<<1],s[x<<1|1])+lz[x];
}
int q(int x,int l,int r,int nw){
	if(l==r)return l;int m=(l+r)>>1;nw+=lz[x];
	return s[x<<1|1]+nw>0?q(x<<1|1,m+1,r,nw):q(x<<1,l,m,nw);
}
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",&a[i]);
		f(1,1,a[i],1,1,1e6);
	}
	rep(i,1,m){
		scanf("%d",&b[i]);
		f(1,1,b[i],-1,1,1e6);
	}int k;
	scanf("%d",&k);
	rep(o,1,k){int op,i,x;
		scanf("%d%d%d",&op,&i,&x);
		if(op==1){
			f(1,1,a[i],-1,1,1e6);a[i]=x;
			f(1,1,a[i],1,1,1e6);
		}else{
			f(1,1,b[i],1,1,1e6);b[i]=x;
			f(1,1,b[i],-1,1,1e6);
		}
		printf("%d\n",s[1]>0?q(1,1,1e6,0):-1);
	}
}