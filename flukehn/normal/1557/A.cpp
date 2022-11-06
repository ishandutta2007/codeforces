#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int a[N];
int n;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(10);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		sort(a,a+n);
		double ret=0;
		for(int i=0;i<n;++i)ret+=a[i];
		double sum=0,ans=-2e9;
		for(int i=0;i<n-1;++i){
			sum+=a[i];
			ans=max(ans,sum/(i+1)+(ret-sum)/(n-i-1));
		}
		cout<<ans<<"\n";	
	}
}