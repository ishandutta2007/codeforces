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
const int N=2e5+10;
const int M=6e6+10;
const int mo=1e9+7;
struct pr{int x,y;}a[N];
bool cmp(pr a,pr b){return a.y==b.y?a.x<b.x:a.y>b.y;}
int tot,s[M],ls[M],rs[M];
int q(int x,int L,int R,int l,int r){
	if(L<=l&&R>=r)return s[x];int m=(l+r)>>1;
	return (L<=m&&ls[x]?q(ls[x],L,R,l,m):0)+(R>m&&rs[x]?q(rs[x],L,R,m+1,r):0);
}
void f(int x,int y,int l,int r){
	if(l==r){s[x]=1;return;}int m=(l+r)>>1;
	if(y<=m){
		if(!ls[x])ls[x]=++tot;
		f(ls[x],y,l,m);
	}else{
		if(!rs[x])rs[x]=++tot;
		f(rs[x],y,m+1,r);
	}
	s[x]=(ls[x]?s[ls[x]]:0)+(rs[x]?s[rs[x]]:0);
}
int main(){int n;
	scanf("%d",&n);ll ans=0;tot=1;
	rep(i,1,n)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);int x=0;
	rep(i,1,n)if(i==n||a[i].y>a[i+1].y){
		ll d=a[x+1].x>1?q(1,1,a[x+1].x-1,1,1e9):0;
		ans-=d*(d+1)/2;
		rep(j,x+1,i){
			if(j>x+1){
				d=a[j-1].x+1<a[j].x?q(1,a[j-1].x+1,a[j].x-1,1,1e9):0;
				ans-=d*(d+1)/2;
			}f(1,a[j].x,1,1e9);
		}x=i;
		d=a[i].x<1e9?q(1,a[i].x+1,1e9,1,1e9):0;
		ans-=d*(d+1)/2;
		ans+=1ll*s[1]*(s[1]+1)/2;
	}
	printf("%lld\n",ans);
}