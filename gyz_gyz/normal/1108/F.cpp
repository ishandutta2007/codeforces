#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define N 1000010
using namespace std;
typedef long long ll;
struct pr{int x,y;ll w;}a[N];int f[N];
bool cmp(pr x,pr y){return x.w<y.w;}
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main(){int n,m;
	scanf("%d%d",&n,&m);int ans=1-n;
	rep(i,1,m)scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].w);
	sort(a+1,a+m+1,cmp);rep(i,1,n)f[i]=i;
	rep(i,1,m){
		if(i==1||a[i].w>a[i-1].w)
			for(int j=i;j<=m&&a[j].w==a[i].w;++j)
				if(gf(a[j].x)!=gf(a[j].y))++ans;
		if(gf(a[i].x)!=gf(a[i].y))f[gf(a[i].x)]=gf(a[i].y);
	}
	printf("%d\n",ans);	
}