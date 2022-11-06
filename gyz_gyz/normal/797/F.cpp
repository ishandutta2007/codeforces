#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define fr first
#define sc second
#define N 100010
using namespace std;
typedef long long ll;
ll a[2][N];pair<ll,int>p[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);bool t=0;
	rep(i,1,n){
		scanf("%lld",&p[i].fr);p[i].sc=-1;
	}
	rep(i,1,m)scanf("%lld%d",&p[i+n].fr,&p[i+n].sc);
	sort(p+1,p+n+m+1);p[0].fr=p[1].fr;
	rep(i,n+1,n+5000)a[0][i]=1e18;
	rep(i,1,n+m){t^=1;
		rep(j,0,n+5000){
			ll s=min(n+5000,max(j-p[i].sc,0));
			a[t][j]=a[t^1][s]+(p[i].fr-p[i-1].fr)*abs(n-s);
		}
		dep(j,n+5000,1)a[t][j-1]=min(a[t][j-1],a[t][j]);
	}
	printf("%lld\n",a[t][n]>=1e18?-1:a[t][n]);
}