#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,K;
ll a[100005],b[100005];
void Solve(){
	scanf("%d%d",&n,&K);
	for(int i=n-K+1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=n-K+2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(i>n-K+2&&b[i]<b[i-1]){
			cout<<"No\n";
			return ;
		}
	}
	ll bound=1e10;
	if(n-K+2<=n)bound=b[n-K+2];
	if(bound*(n-K+1)<a[n-K+1])puts("No");
	else puts("Yes");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}