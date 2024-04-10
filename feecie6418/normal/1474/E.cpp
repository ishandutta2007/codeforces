#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans=0,a[100005];
void Solve(){
	cin>>n,ans=0;
	for(int i=1;i<=n;i++)a[i]=i;
	if(n&1){
		swap(a[1],a[n]),ans+=1ll*(n-1)*(n-1);
		for(int i=2;i<=n/2;i++)swap(a[1],a[n-i+1]),swap(a[i],a[n]),ans+=2ll*(n-i)*(n-i);
		swap(a[1],a[(n+1)/2]),ans+=1ll*((n-1)/2)*((n-1)/2);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)cout<<a[i]<<' ';
		puts("");
		cout<<n-1<<'\n';
		cout<<(n+1)/2<<' '<<1<<'\n';
		for(int i=n/2;i>1;i--)cout<<i<<' '<<n<<'\n',cout<<n-i+1<<' '<<1<<'\n';
		cout<<1<<' '<<n<<'\n';
	}
	else {
		swap(a[1],a[n]),ans+=1ll*(n-1)*(n-1);
		for(int i=2;i<=n/2;i++)swap(a[1],a[n-i+1]),swap(a[i],a[n]),ans+=2ll*(n-i)*(n-i);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)cout<<a[i]<<' ';
		puts("");
		cout<<n-1<<'\n';
		for(int i=n/2;i>1;i--)cout<<i<<' '<<n<<'\n',cout<<n-i+1<<' '<<1<<'\n';
		cout<<1<<' '<<n<<'\n';
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}