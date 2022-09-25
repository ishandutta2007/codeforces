#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;++i){
		cout<<(s[i]=='D'?'U':(s[i]=='U'?'D':s[i]));	
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}