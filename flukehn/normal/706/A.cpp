#include<bits/stdc++.h>
using namespace std;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	double a,b;
	while(cin>>a>>b){
		int n;
		cin>>n;
		double ans=1e9;
		for(int i=0;i<n;++i){
			double x,y,v;
			cin>>x>>y>>v;
			double d=sqrt((x-a)*(x-a)+(y-b)*(y-b));
			ans=min(ans,d/v);
		}
		cout<<ans<<"\n";
	}
}