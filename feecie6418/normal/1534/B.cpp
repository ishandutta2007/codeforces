#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[400005],b[400005];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]&&a[i]>a[i+1]){
			ans+=a[i]-max(a[i-1],a[i+1]);
			b[i]=max(a[i-1],a[i+1]);
		}
		else b[i]=a[i];
	}
	for(int i=0;i<=n;i++)ans+=abs(b[i]-b[i+1]);
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)a[i]=b[i]=0;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}