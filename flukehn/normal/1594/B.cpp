#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	int n,k;
	const int mo=1e9+7;
	while(cin>>n>>k){
		int t=1;
		int ans=0;
		for(int i=0;i<=30;++i,t=1ll*t*n%mo){
			if(k>>i&1)ans=(ans+t)%mo;
		}
		cout<<ans<<"\n";
	}
}