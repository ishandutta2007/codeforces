#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 100010
#define mo 998244353
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,a[N];ll f[2][205],g[2][205],ff[2][205],gg[2][205];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	if(~a[1])f[1][a[1]]=1;
	else rep(i,1,200)f[1][i]=1;
	rep(i,1,200)ff[1][i]=(ff[1][i-1]+f[1][i])%mo;
	rep(i,2,n){
		rep(j,1,200)if(a[i]==-1||a[i]==j){
			f[i&1][j]=(ff[(i&1)^1][j]+gg[(i&1)^1][j+1])%mo;
			g[i&1][j]=(f[(i&1)^1][j]+gg[(i&1)^1][j+1])%mo;
		}else f[i&1][j]=g[i&1][j]=0;
		rep(j,1,200)ff[i&1][j]=(ff[i&1][j-1]+f[i&1][j])%mo;
		dep(j,200,1)gg[i&1][j]=(gg[i&1][j+1]+g[i&1][j])%mo;
	}
	printf("%I64d\n",gg[n&1][1]);
}