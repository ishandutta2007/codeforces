#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
const double pi=acos(-1);
double x[N],y[N];
double w[N];
int n;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>x[i]>>y[i];
		w[i]=atan2(y[i],x[i]);
	}
	sort(w,w+n);
	double ans=0;
	for(int i=0;i<n-1;++i){
		ans=max(ans,w[i+1]-w[i]);
	}
	ans=max(ans,2*pi-w[n-1]+w[0]);
	ans=2*pi-ans;
	ans=ans/pi*180.0;
	cout<<fixed<<setprecision(10)<<ans<<endl;
}