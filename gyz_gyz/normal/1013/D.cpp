#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 3000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,k,x,y,ans,f[N];bool v[N];
struct pr{int x,y;}a[N];
bool cmp(pr x,pr y){return x.x<y.x;}
int gf(int x){
	if(f[x]==x)return x;
	f[x]=gf(f[x]);return f[x];
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,k)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+k+1,cmp);
	rep(i,1,m)f[i]=i;
	rep(i,1,k-1)if(a[i].x==a[i+1].x){
		x=gf(a[i].y);y=gf(a[i+1].y);
		if(x!=y)f[x]=y;
	}
	rep(i,1,k)v[a[i].x]=1;ans=-1;
	rep(i,1,n)if(!v[i])ans++;
	rep(i,1,m)if(f[i]==i)ans++;
	printf("%d\n",ans);
}