#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1<<9;
int n,k,m,ans,X[N],Y[N];
long long a[N][N],b[N][N];
int main(){
	ios::sync_with_stdio(false),cin>>k,n=(1<<k)-1;
	FOR(i,0,n)FOR(j,0,n)cin>>a[i][j];
	cin>>m;FOR(i,1,m)cin>>X[i]>>Y[i];
	FOR(_,1,k){
		swap(a,b),memset(a,0,sizeof(a));
		FOR(i,0,n)FOR(j,0,n)FOR(p,1,m)
			a[i+X[p]&n][j+Y[p]&n]^=b[i][j];
		FOR(i,1,m)(X[i]<<=1)&=n,(Y[i]<<=1)&=n;
	}
	FOR(i,0,n)FOR(j,0,n)ans+=!!a[i][j];
	return cout<<ans,0;
}