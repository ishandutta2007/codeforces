#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a[100005];
ll cnt[100005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i],cnt[i]=0;
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(cnt[i]>a[i]-1)cnt[i+1]+=cnt[i]-a[i]+1,cnt[i]=a[i]-1;
			ans+=a[i]-cnt[i]-1;
			for(int j=i+2;j<=i+a[i]&&j<=n;j++)cnt[j]++;
		}
		cout<<ans<<'\n';
	}
}