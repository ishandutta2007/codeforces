#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
const int N=6e5;
const ll mo=1e9+7;
const ll inf=1e9;
const ll Inf=1e18;
int lz[N],a[N],ls[N],rs[N],mi[N],mx[N];
bool ok[N];char s[N];
void f(int x,int l,int r,int y,int z,int L,int R){
	if(l==L&&r==R&&(!z||(L==R))){
		if(z)ok[x]^=1;
		lz[x]+=y;mi[x]+=y;mx[x]+=y;
		ls[x]-=y;rs[x]-=y;
		return;
	}
	int m=(L+R)/2;
	if(lz[x]){
		lz[x*2]+=lz[x];mi[x*2]+=lz[x];mx[x*2]+=lz[x];
		ls[x*2]-=lz[x];rs[x*2]-=lz[x];
		lz[x*2+1]+=lz[x];mi[x*2+1]+=lz[x];mx[x*2+1]+=lz[x];
		ls[x*2+1]-=lz[x];rs[x*2+1]-=lz[x];
		lz[x]=0;
	}
	if(r<=m)f(x*2,l,r,y,z,L,m);
	else if(l>m)f(x*2+1,l,r,y,z,m+1,R);
	else{
		f(x*2,l,m,y,z,L,m);f(x*2+1,m+1,r,y,0,m+1,R);
	}
	ok[x]=ok[x*2]|ok[x*2+1];
	mi[x]=min(mi[x*2],mi[x*2+1]);	
	if(!ok[x*2]){
		mx[x]=mx[x*2+1];ls[x]=ls[x*2+1];a[x]=a[x*2+1];
		rs[x]=max(mx[x*2+1]-mi[x*2]*2,rs[x*2+1]);
	}else if(!ok[x*2+1]){
		mx[x]=mx[x*2];rs[x]=rs[x*2];a[x]=a[x*2];
		ls[x]=max(mx[x*2]-mi[x*2+1]*2,ls[x*2]);
	}else{
		mx[x]=max(mx[x*2],mx[x*2+1]);
		ls[x]=max(mx[x*2]-mi[x*2+1]*2,max(ls[x*2],ls[x*2+1]));
		rs[x]=max(mx[x*2+1]-mi[x*2]*2,max(rs[x*2],rs[x*2+1]));
		a[x]=max(max(ls[x*2]+mx[x*2+1],mx[x*2]+rs[x*2+1]),max(a[x*2],a[x*2+1]));
	}
}
int main(){int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	f(1,0,0,0,1,0,n*2-2);
	rep(i,1,n*2-2){
		if(s[i]=='(')f(1,i,n*2-2,1,1,0,n*2-2);
		else f(1,i,n*2-2,-1,0,0,n*2-2);
	}
	printf("%d\n",a[1]);
	rep(i,1,m){int l,r;
		scanf("%d%d",&l,&r);
		if(l>r)swap(l,r);
		if(s[l]!=s[r]){
			if(s[l]=='(')f(1,l,r-1,-2,1,0,n*2-2);
			else f(1,l,r-1,2,1,0,n*2-2);
			f(1,r,r,0,1,0,n*2-2);
			swap(s[l],s[r]);
		}
		printf("%d\n",a[1]);
	}
}