#include<bits/stdc++.h>
using namespace std;
#define N 1010
const int mod=1e9+7;
typedef long long ll;
int T,C[N][N],n,cnt[N],m;
void init(int n){
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cnt[i]=0;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		++cnt[x];
	}
	for(int i=n;i>=1;--i){
		if(cnt[i]>=m){
			cout<<C[cnt[i]][m]<<'\n';
			return;
		}
		m-=cnt[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(1000);
	cin>>T;
	while(T--)Solve();
	return 0;
}