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
	int T;cin>>T;
	int n;
	while(cin>>n){
		vector<int> a,b;
		for(int i=0;i<2*n;++i){
			int x,y;
			cin>>x>>y;
			if(!x)a.push_back(abs(y));
			else b.push_back(abs(x));
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		double ans1=0,ans2=0;
		for(int i=0;i<n;++i){
			ans1+=sqrt(1ll*a[i]*a[i]+1ll*b[i]*b[i]);
			ans2+=sqrt(1ll*a[i]*a[i]+1ll*b[n-i-1]*b[n-i-1]);
		}
		cout<<min(ans1,ans2)<<"\n";
	}
}