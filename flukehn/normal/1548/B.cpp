#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+11;
int Log[N];
int n;
ll a[N];
ll b[21][N];
ll ask(int l,int r){
	int k=Log[r-l+1];
	return __gcd(b[k][l],b[k][r-(1<<k)+1]);
}
int main(){
#ifdef flukehn
	freopen("b.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	Log[0]=-1;
	for(int i=1;i<N;++i)Log[i]=Log[i>>1]+1;
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)b[0][i]=abs(a[i]-a[i-1]);
		for(int i=1;(1<<i)<=n;++i)
			for(int j=1;j+(1<<i)-1<=n;++j)
				b[i][j]=__gcd(b[i-1][j],b[i-1][j+(1<<i-1)]);
		int ans=1;
		for(int i=1;i<n;++i){
			if(ask(i+1,n)!=1){
				ans=max(ans,n-i+1);
				continue;
			}
			int l=i+1,r=n;
			while(l<r){
				int m=(l+r)>>1;
				if(ask(i+1,m)==1) r=m;
				else l=m+1;
			}
			ans=max(ans,l-i);
		}
		cout<<ans<<"\n";
	}
}