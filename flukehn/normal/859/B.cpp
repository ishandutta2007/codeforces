#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	//int T;cin>>T;
	int n;
	while(cin>>n){
		int ans=1e9;
		for(int i=1;i<=n;++i){
			int j=(n+i-1)/i;
			ans=min(ans,2*(i+j));
		}
		cout<<ans<<"\n";
	}
}