#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int n;
int a[N],b[N];
int sa[N],sb[N];
int main(){
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)cin>>b[i];
		sa[0]=0;
		sb[n+1]=0;
		for(int i=1;i<=n;++i)sa[i]=sa[i-1]+b[i];
		for(int i=n;i>=1;--i)sb[i]=sb[i+1]+a[i];
		int ans=sb[1];
		for(int i=1;i<=n;++i)
			ans=min(ans,max(sa[i-1],sb[i+1]));
		cout<<ans<<"\n";
	}
}