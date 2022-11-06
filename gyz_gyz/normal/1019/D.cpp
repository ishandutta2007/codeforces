#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 3000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define Pi acos(-1.)
#define eps 1e-8
using namespace std;
int n,tot,l,r,m,x[N],y[N],p[N],t[N];ll s,d;
struct pr{int x,y;double z;}a[N*N];
bool cmp0(int i,int j){
	if(x[i]==x[j])return y[i]<y[j];return x[i]>x[j];
}
bool cmp(pr x,pr y){return x.z<y.z;}
ll cal(int a,int b,int c){
	return 1ll*x[a]*y[b]+1ll*x[b]*y[c]+1ll*x[c]*y[a]
	-1ll*x[b]*y[a]-1ll*x[c]*y[b]-1ll*x[a]*y[c];
}
void fd(int i,ll s){
	l=1;r=n;m=(l+r)/2;
	for(;l<=r;m=(l+r)/2){
		d=cal(a[i].x,a[i].y,p[m]);
		if(d==s*2)break;
		if(d<s*2)l=m+1;
		if(d>s*2)r=m-1;
	}
	if(d==s*2){
		printf("Yes\n%d %d\n%d %d\n%d %d",
		x[a[i].x],y[a[i].x],x[a[i].y],y[a[i].y],x[p[m]],y[p[m]]);exit(0);
	}
}
int main(){
	scanf("%d%I64d",&n,&s);
	rep(i,1,n)scanf("%d%d",&x[i],&y[i]);
	rep(i,1,n)rep(j,1,n)if(i!=j){
		a[++tot].x=i;a[tot].y=j;a[tot].z=atan2(x[i]-x[j],y[i]-y[j]);
	}
	sort(a+1,a+tot+1,cmp);
	rep(i,1,n)p[i]=i;
	sort(p+1,p+n+1,cmp0);
	rep(i,1,n)t[p[i]]=i;
	rep(i,1,tot){
		swap(p[t[a[i].x]],p[t[a[i].y]]);
		swap(t[a[i].x],t[a[i].y]);
		fd(i,-s);fd(i,s);
	}
	printf("No");
}