#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],g,k;
int n;
void Solve(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1),g=a[2]-a[1];
	for(int i=3;i<=n;i++)g=__gcd(g,a[i]-a[i-1]);
	if((k-a[1])%g)puts("NO");
	else puts("YES");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}