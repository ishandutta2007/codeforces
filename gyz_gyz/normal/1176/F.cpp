#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int mo=1e9+7;
const ll Inf=1e18;
ll a[N][10],b[4][4],c[4][4];pair<ll,int>p[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,0,n)rep(j,0,9)a[i][j]=-Inf;a[0][0]=0;
	rep(i,1,n){int m;
		scanf("%d",&m);
		rep(j,1,m)scanf("%d%lld",&p[j].sc,&p[j].fr);
		sort(p+1,p+m+1);
		rep(j,0,3)rep(k,1,3)b[j][k]=c[j][k]=-Inf;
		rep(j,1,m)dep(k,3,p[j].sc)rep(l,1,3){
			b[k][l]=max(b[k][l],b[k-p[j].sc][l-1]+p[j].fr);
			c[k][l]=max(c[k][l],b[k-p[j].sc][l-1]+p[j].fr*2);
		}
		rep(j,0,9)rep(k,0,3){
			if(j<k)a[i][j]=max(a[i][j],a[i-1][j-k+10]+c[3][k]);
			else a[i][j]=max(a[i][j],a[i-1][j-k]+b[3][k]);
		}
	}ll ans=0;
	rep(i,0,9)ans=max(ans,a[n][i]);
	printf("%lld\n",ans);
}