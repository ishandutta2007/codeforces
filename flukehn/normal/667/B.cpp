#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
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
		vector<int> a(n);
		for(int i=0;i<n;++i)cin>>a[i];
		sort(a.begin(),a.end(),greater<int>());
		int ans=a[0]+1;
		for(int i=1;i<n;++i)ans-=a[i];
		cout<<ans<<"\n";
	}
}