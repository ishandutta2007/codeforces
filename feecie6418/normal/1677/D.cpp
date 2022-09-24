#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,a[1000005];
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n-m+1;i<=n;i++){
		if(a[i]==-1)a[i]=0;
		if(a[i]!=0)return puts("0"),void();
	}
	int ans=1;
	for(int i=n;i>m;i--){
		a[i]=a[i-m];
		if(a[i]>0)a[i]+=m;
		else if(a[i]==0)ans=1ll*ans*(m+1)%mod;
	}
	for(int i=1;i<=m;i++)a[i]=-1;
	for(int i=1;i<=n;i++)if(a[i]==-1)ans=1ll*ans*i%mod;
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}