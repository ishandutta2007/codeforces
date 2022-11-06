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
#define N 3000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 998244353
#define eps 1e-8
using namespace std;
int n,tot,l,r,m;bool u;
int a[N],b[N],p[N],f[N];
int gf(int x){
	if(f[x]==x)return x;
	f[x]=gf(f[x]);return f[x];
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&a[i],&b[i]);
	 	p[i]=a[i];p[n+i]=b[i];
	}
	sort(p+1,p+n*2+1);tot=unique(p+1,p+n*2+1)-(p+1);
	rep(i,1,n){
		a[i]=lower_bound(p+1,p+tot+1,a[i])-p;
		b[i]=lower_bound(p+1,p+tot+1,b[i])-p;
	}
	l=1;r=tot+1;m=(l+r)/2;p[r]=-1;
	for(;l<r;m=(l+r)/2){
		rep(i,1,tot+1)f[i]=i;u=1;
		rep(i,1,n){gf(a[i]);gf(b[i]);
			if((f[a[i]]>m)&&(f[b[i]]>m)){u=0;break;}
			if((f[b[i]]>m)||(f[a[i]]==f[b[i]]))f[f[a[i]]]=tot+1;
			else if(f[a[i]]>m)f[f[b[i]]]=tot+1;else f[f[a[i]]]=f[b[i]];
		}
		if(u)r=m;else l=m+1;
	}
	printf("%d\n",p[m]);
}