#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll x;
void Solve(){
	string ans,s;
	cin>>n>>k>>x;
	--x;
	cin>>s;
	reverse(s.begin(),s.end());
	int cnt=0;
	auto Gao=[&](int ct)->void{
		int t=cnt*k+1;
		int z=x%t;x/=t;
		while(z--)ans+='b';
	};
	for(auto c:s){
		if(c=='a')Gao(cnt),cnt=0,ans+=c;
		else ++cnt;
	}	
	Gao(cnt);
	reverse(ans.begin(),ans.end());
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}