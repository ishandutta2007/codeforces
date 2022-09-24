#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,a[100005];
ll ans=0;
typedef pair<int,int> pr;
void Solve(){
	scanf("%d",&n),ans=0;
	//n=100000;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	//for(int i=1;i<=n;i++)a[i]=100001-i;
	vector<pr> val;
	for(int i=n;i>=1;i--){
		int pos=0;
		ll t=0;
		vector<pr> to;
		for(int j=1,k;j<=a[i]-1;j=k+1){
			k=(a[i]-1)/((a[i]-1)/j);
			int sum=0;
			while(pos<val.size()&&val[pos].first<=k)sum+=val[pos].second,pos++;
			t+=1ll*((a[i]-1)/j)*sum;
			to.push_back(pr(a[i]/((a[i]-1)/j+1),sum));
		}
		int sum=0;
		while(pos<val.size())sum+=val[pos].second,pos++;
		to.push_back(pr(a[i],sum+1));
		val=to;
		t%=mod,ans=(ans+1ll*t*i)%mod;
	}
	cout<<ans<<'\n';
} 
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}