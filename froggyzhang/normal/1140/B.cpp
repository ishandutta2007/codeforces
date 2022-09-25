#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
void Solve(){
	cin>>n>>s;
	int i=0;
	while(s[i]=='<'&&s[n-i-1]=='>')++i;
	cout<<i<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}