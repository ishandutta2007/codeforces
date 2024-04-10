#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
int f[35][N],s[35][N];ll w[35][N];
int main(){int n;ll m;
	scanf("%d%lld",&n,&m);
	rep(i,0,n-1)scanf("%d",&f[0][i]);
	rep(i,0,n-1){
		scanf("%d",&s[0][i]);
		w[0][i]=s[0][i];
	}
	rep(i,1,34)rep(j,0,n-1){
		f[i][j]=f[i-1][f[i-1][j]];
		w[i][j]=w[i-1][j]+w[i-1][f[i-1][j]];
		s[i][j]=min(s[i-1][j],s[i-1][f[i-1][j]]);
	}
	rep(i,0,n-1){
		ll r=m;int x=i,z=1e9;ll y=0;
		dep(j,34,0)if(r>>j){
			y+=w[j][x];
			z=min(z,s[j][x]);
			x=f[j][x];r-=1ll<<j;
		}
		printf("%lld %d\n",y,z);
	}
}