#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	string s;
	cin>>s;
	int cnt=0;
	for(auto x:s){
		cnt+=!((x-'0')&1);
	}
	if(!cnt){
		cout<<-1<<'\n';
	}
	else if(!((s.back()-'0')&1)){
		cout<<0<<'\n';
	}
	else if(!((s[0]-'0')&1)){
		cout<<1<<'\n';
	}
	else{
		cout<<2<<'\n';
	}	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}