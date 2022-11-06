#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define ll long long
#define N 400000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int n,m,b[N];ll p[N],q[N],s[N];
struct pr{ll x,y;int id;}a[N];
bool cmp(pr x,pr y){return x.x-x.y<y.x-y.y;}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%lld%lld",&a[i].x,&a[i].y);a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	rep(i,1,n)b[a[i].id]=i;
	rep(i,1,n)p[i]=p[i-1]+a[i].x;
	dep(i,n,1)q[i]=q[i+1]+a[i].y;
	rep(i,1,n)s[a[i].id]=p[i-1]+q[i+1]+a[i].y*(i-1)+a[i].x*(n-i);
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		if(!cmp(a[b[x]],a[b[y]]))swap(x,y);
		int sr=a[b[x]].x+a[b[y]].y;
		s[x]-=sr;s[y]-=sr;
	}
	rep(i,1,n)printf("%lld ",s[i]);
}