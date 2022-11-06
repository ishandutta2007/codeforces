#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int n,k;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>k;
		long long ans=-(~0uLL>>2);
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=max(1,n-2*k+1);i<=n;++i)
			for(int j=i+1;j<=n;++j)
				ans=max(ans,1LL*i*j-1LL*k*(a[i]|a[j]));
		cout<<ans<<"\n";
	}
}