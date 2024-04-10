#include<bits/stdc++.h>
using namespace std;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	int n,k;
	while(cin>>n>>k){
		double ans=0;
		double a,b,u,v;
		cin>>a>>b;
		u=a,v=b;
		for(int i=2;i<=n;++i){
			double x,y;
			cin>>x>>y;
			ans+=sqrt((x-a)*(x-a)+(y-b)*(y-b));
			a=x,b=y;
		}
		//ans=(ans*k+(k-1)*sqrt((a-u)*(a-u)+(b-v)*(b-v)))/50;
		ans=(ans*k)/50;
		cout<<ans<<"\n";
	}
}