#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int mo=998244353;
const int N=122;
int c[N][N];
int f[N];
int p2[N];
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	for(int i=0;i<N;++i){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;++j){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
		}
	}
	p2[0]=1;
	for(int i=1;i<N;++i)p2[i]=p2[i-1]*2%mo;
	f[0]=0;
	for(int i=1;i<=60;++i) {
		f[i]=(1LL*c[2*i-1][i] + c[i*2-2][i-1]-1-f[i-1]+mo) % mo;
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		n/=2;
		int x=f[n];
		int y=(1LL*c[2*n][n]-1-x+mo)%mo;
		int z=1;
		cout<<x<<" "<<y<<" "<<z<<"\n";
	}
}