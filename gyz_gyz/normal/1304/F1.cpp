#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e4+10;
const int mo=1e9+7;
const int inf=1e9;
int a[55][N],f[55][N],ml[55][N],mr[55][N];
int main(){int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)rep(j,1,m){
		scanf("%d",&a[i][j]);
		a[i][j]+=a[i][j-1];
	}
	rep(i,1,m-k+1){
		f[1][i]=a[1][i+k-1]-a[1][i-1];
		ml[1][i]=max(ml[1][i-1],f[1][i]+a[2][i+k-1]-a[2][i-1]);
	}
	dep(i,m-k+1,1)mr[1][i]=max(mr[1][i+1],f[1][i]+a[2][i+k-1]-a[2][i-1]);
	rep(i,2,n){
		rep(j,1,m-k+1){
			int L=max(j-k+1,1),R=min(j+k-1,m-k+1);
			f[i][j]=max(ml[i-1][L-1],mr[i-1][R+1])+a[i][j+k-1]-a[i][j-1];
			rep(l,L,R)f[i][j]=max(f[i][j],f[i-1][l]+a[i][max(j,l)+k-1]-a[i][min(j,l)-1]);
			ml[i][j]=max(ml[i][j-1],f[i][j]+a[i+1][j+k-1]-a[i+1][j-1]);
		}
		dep(j,m-k+1,1)mr[i][j]=max(mr[i][j+1],f[i][j]+a[i+1][j+k-1]-a[i+1][j-1]);
	}int ans=0;
	rep(i,1,m-k+1)ans=max(ans,f[n][i]);
	printf("%d\n",ans);
}