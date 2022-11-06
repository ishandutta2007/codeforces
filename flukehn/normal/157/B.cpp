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
		vector<int> r(n);
		for(int i=0;i<n;++i)cin>>r[i];
		sort(r.begin(),r.end(),greater<int>());
		long long ans=0;
		for(int i=0;i<n;++i){
			if(i%2)ans-=1ll*r[i]*r[i];
			else ans+=1ll*r[i]*r[i];
		}
		cout<<ans*acos(-1)<<"\n";
	}
}