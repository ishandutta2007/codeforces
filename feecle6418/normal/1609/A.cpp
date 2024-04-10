#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,a[17],ans=0,b[17];
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)b[j]=a[j];
			ll sum=0;
			for(int j=1;j<=n;j++){
				if(j!=i){
					while(b[j]%2==0)b[j]/=2,b[i]*=2;
				}
			}
			for(int j=1;j<=n;j++)sum+=b[j];
			ans=max(ans,sum);
		}
		cout<<ans<<'\n';
	}
}