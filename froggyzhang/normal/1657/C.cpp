#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
void Solve(){
	cin>>n>>s;
	int j=0,t=0;
	for(int i=1;i<n;++i){
		if((s[j]=='('&&s[i]==')')||s[j]==s[i])++t,j=++i;
	}
	cout<<t<<' '<<n-j<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}