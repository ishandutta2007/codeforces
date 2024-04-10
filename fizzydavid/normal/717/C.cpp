//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const ll mod=10007;
int n;
ll a[100111];
int main()
{
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)ans=(ans+a[i]*a[n-i+1])%mod;
	cout<<ans<<endl;
	return 0;
}