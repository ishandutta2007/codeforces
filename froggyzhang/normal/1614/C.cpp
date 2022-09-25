#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const int mod=1e9+7;
int pw2[N],n,m;
void init(int n){
	pw2[0]=1;
	for(int i=1;i<=n;++i){
		pw2[i]=(pw2[i-1]<<1)%mod;
	}
}
void Solve(){
	cin>>n>>m;
	int ans=0,ok=0;
	for(int i=1;i<=m;++i){
		int l,r,x;
		cin>>l>>r>>x;
		ok|=x;
	}
	for(int i=0;i<30;++i){
		if(ok>>i&1)ans=(ans+1LL*pw2[n-1]*(1<<i))%mod;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(200000);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}