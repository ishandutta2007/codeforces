#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void Solve(){
	cin>>s;
	s[0]=s.back();
	cout<<s<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}