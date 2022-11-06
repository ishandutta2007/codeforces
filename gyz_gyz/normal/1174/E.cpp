#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int mo=1e9+7;
ll a[2][2][25];int n,m,s[2][25];
int main(){
	scanf("%d",&n);while(n>>(m+1))++m;s[0][0]=n;
	rep(i,1,m)s[0][i]=n>>i,s[1][i]=n/((1<<(i-1))*3);
	a[0][1][m+1]=1;int t=0;
	rep(i,1,n){
		t^=1;a[t][0][m+1]=a[t][1][m+1]=0;
		rep(j,0,m){
			a[t][0][j]=(a[t^1][0][j]*max(s[0][j]-(i-1),0)+a[t^1][0][j+1]*(s[0][j]-s[0][j+1])+a[t^1][1][j+1]*(s[0][j]-s[1][j+1]))%mo;
			a[t][1][j]=j?(a[t^1][1][j]*max(s[1][j]-(i-1),0)+a[t^1][1][j+1]*(s[1][j]-s[1][j+1]))%mo:0;
		}
	}
	printf("%lld\n",a[t][0][0]);
}