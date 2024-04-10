#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
void Solve(){
	cin>>n>>s;
	s=' '+s;
	ll ans=1LL*n*(n-1)/2-(n<<1);
	for(int i=1;i<n;++i){
		ans+=(s[i]-'A')^(s[i+1]-'A');
	}
	++ans,++ans;
	for(int i=2;i<=n;++i,++ans){
		if(s[i]^s[i-1])break;
	}
	for(int i=n-1;i>=1;--i,++ans){
		if(s[i]^s[i+1])break;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	while(T--)Solve();
	return 0;
}