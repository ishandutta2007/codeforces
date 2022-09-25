#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n,K,phi[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>K;
	if(K==1){cout<<3<<'\n';return 0;}
	for(int i=1;i<=n;++i)phi[i]=i;
	for(int i=2;i<=n;++i){
		if(phi[i]==i){
			for(int j=1;i*j<=n;++j){
				phi[i*j]-=phi[i*j]/i;
			}
		}
	}
	sort(phi+3,phi+n+1);
	ll ans=2;
	for(int i=3;i<=K+2;++i)ans+=phi[i];
	cout<<ans<<'\n';
	return 0;
}