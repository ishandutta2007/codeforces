#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e3+10;
const int inf=1e6;
const int INF=1e9;
int a[N],f[2][N][N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,0,n)rep(j,0,n)f[0][i][j]=f[1][i][j]=n+1;
	f[0][0][0]=f[1][0][0]=0;
	rep(i,1,n)rep(j,0,i){
		if(j&&(!(a[i]&1)))f[0][i][j]=min(f[0][i-1][j-1],f[1][i-1][j-1]+1);
		if(!a[i]||(a[i]&1))f[1][i][j]=min(f[0][i-1][j]+1,f[1][i-1][j]);
	}
	printf("%d\n",min(f[0][n][n/2],f[1][n][n/2]));	
}