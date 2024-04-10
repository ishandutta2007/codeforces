#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200010
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 998244353
#define inf 1000000000
#define eps 1e-8
using namespace std;
int n,tot,L[N],R[N];ll l[N],r[N];
struct pr{int x,y;}a[N];
bool cmp(pr x,pr y){
	if(max(x.x,x.y)==max(y.x,y.y)){
		if(x.x==y.x)return x.y>y.y;
		return x.x<y.x;
	}
	return max(x.x,x.y)<max(y.x,y.y);
}
ll dis(int x,int y){
	return abs(a[x].x-a[y].x)+abs(a[x].y-a[y].y);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	rep(i,1,n)if(max(a[i].x,a[i].y)!=max(a[i-1].x,a[i-1].y)){
		R[tot]=i-1;L[++tot]=i;
	}R[tot]=n;
	rep(i,1,tot){
		l[i]=min(l[i-1]+dis(R[i],L[i-1]),r[i-1]+dis(R[i],R[i-1]))+dis(L[i],R[i]);
		r[i]=min(l[i-1]+dis(L[i],L[i-1]),r[i-1]+dis(L[i],R[i-1]))+dis(L[i],R[i]);
	}
	printf("%I64d",min(l[tot],r[tot]));
}