#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
template<class T>
inline bool upmx(T &x,T y){return x<y?x=y,1:0;}
const int N=505;
int f[N][N];
int a[N];
int n;
int solve(){
	for(int i=1;i<=n;++i)cin>>a[i];
	memset(f,-0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;++i) {
		for(int j=0;j<i;++j) {
			int p=i-j-2;
			for(int k=j;k>=0&&k-p>=0;--k){
				upmx(f[i][k-p], f[j][k] + (i-j)*a[i]);
			}
		}
		//for(int j=0;j<=i;++j) debug(f[i][j]<<" \n"[j==i]);
		for(int j=i+1;j<=n;++j)
			for(int k=0;k<=i;++k)
				upmx(f[j][k], f[i][k]+(j-i)*a[i]);
		if(i>=2) {
			for(int j=0;j<i-1;++j) {
				int p=i-1-j-1;
				for(int k=j;k>=0&&k-p>=0;--k){
					upmx(f[i-1][k-p], f[j][k]+(i-1-j) * (a[i]));
				}
			}
		}
		//for(int j=0;j<=i;++j) debug(f[i][j]<<" \n"[j==i]);
	}
	int ans=0;
	for(int i=0;i<=n;++i) upmx(ans, f[n][i]);
	return ans;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	while(cin>>n){
		cout<<solve()<<"\n";
	}
}