#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
void Solve(){
	cin>>n;
	cin>>s;
	int X=1,Y=1;
	for(auto c:s){
		if(c=='R')++Y;
		else ++X;
	}
	if(X==1||Y==1){
		cout<<n<<'\n';
		return;
	}
	ll ans=1LL*(n-X+1)*(n-Y+1);
	reverse(s.begin(),s.end());
	int tx=0,ty=0;
	for(auto c:s){
		if(c=='D')ans+=1LL*(n-X+1)*tx,tx=0,++ty;
		else ans+=1LL*(n-Y+1)*ty,ty=0,++tx;
	}
	cout<<ans+tx+ty<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}