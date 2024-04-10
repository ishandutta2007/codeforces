#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
void Solve(){
	ll n;
	scanf("%lld",&n);
	ll tn=n,tmp=2;
	while(n%2==0)n>>=1,tmp<<=1;
	if((__int128)tmp*(tmp+1)/2<=tn){
		cout<<tmp<<'\n';
		return ;
	}
	if(n>1&&(__int128)n*(n+1)/2<=tn){
		cout<<n<<'\n';
		return ;
	}
	puts("-1");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}