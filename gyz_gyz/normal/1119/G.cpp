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
const int N=1e6+10;
const ll mo=1e9+7;
const ll inf=1e9;
const ll Inf=1e18;
int a[N],b[N];
int main(){int n,m,tot=0;
	scanf("%d%d",&n,&m);int nw=0;
	rep(i,1,m){
		scanf("%d",&a[i]);
		int x=a[i];
		if(x<=nw){
			b[i]=b[i-1]+x;nw-=x;
		}else{
			x-=nw;tot+=x/n;x=x%n;b[i]=x;
			if(x)nw=n-x,++tot;else nw=0;
		}
	}
	sort(b+1,b+m);b[m]=n;
	dep(i,m,1)b[i]=b[i]-b[i-1];
	printf("%d\n",tot);
	rep(i,1,m)printf("%d ",b[i]);printf("\n");int x=1;
	rep(i,1,m){
		while(a[i]>0){
			a[i]-=b[x];printf("%d ",i);
			if(x==m)x=1,printf("\n");else ++x;
		}
	}
	for(;x!=1&&x!=m+1;++x)printf("%d ",m);
}