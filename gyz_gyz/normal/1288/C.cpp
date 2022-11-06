#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int mo=1e9+7;
const int inf=1e9;
const int N=1e3+10;
int a[N][N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	a[1][n]=1;
	rep(i,1,m){
		rep(j,1,n)dep(k,n-1,j)a[j][k]=(a[j][k]+a[j][k+1])%mo;
		rep(j,2,n)rep(k,j,n)a[j][k]=(a[j][k]+a[j-1][k])%mo;
	}
	int ans=0;
	rep(i,1,n)rep(j,i,n)ans=(ans+a[i][j])%mo;
	printf("%d\n",ans);
}