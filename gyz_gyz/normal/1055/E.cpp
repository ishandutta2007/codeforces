#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 2000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,s,m,k,l,r,mid,a[N],f[N][N],t[N],mi[N];
struct pr{int l,r;}p[N];
bool cmp(pr x,pr y){return x.r<y.r;}
bool sol(){int nw=1;
	rep(i,1,n)t[i]=t[i-1]+(a[i]<=mid);
	rep(i,1,n){
		rep(j,0,m)f[i][j]=f[i-1][j];
		if(nw<=s&&mi[nw]<=i)rep(j,1,m)f[i][j]=max(f[i][j],f[mi[nw]-1][j-1]+t[i]-t[mi[nw]-1]);
		while(nw<=s&&p[nw].r==i)nw++;
	}
	return f[n][m]>=k;
}		
int main(){
	scanf("%d%d%d%d",&n,&s,&m,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,s)scanf("%d%d",&p[i].l,&p[i].r);
	sort(p+1,p+s+1,cmp);mi[s]=p[s].l;
	dep(i,s-1,1)mi[i]=min(mi[i+1],p[i].l);
	l=1;r=inf+1;mid=(l+r)/2;
	for(;l<r;mid=(l+r)/2)
		if(sol())r=mid;else l=mid+1;
	if(l>inf)printf("-1\n");else printf("%d\n",l);
}