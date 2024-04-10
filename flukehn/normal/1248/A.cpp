#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	int T;
	cin>>T;
	int n,m;
	while(cin>>n){
		vector<int> p(n);
		for(int i=0;i<n;++i)cin>>p[i];
		cin>>m;
		vector<int> q(m);
		for(int i=0;i<m;++i)cin>>q[i];
		long long ans=0;
		int u=0,v=0;
		for(int i=0;i<n;++i)
			if(p[i]%2)++u;else ++v;
		for(int i=0;i<m;++i)
			if(q[i]%2)ans+=u;else ans+=v;
		cout<<ans<<"\n";
	}
}