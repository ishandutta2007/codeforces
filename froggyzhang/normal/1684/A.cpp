#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	string s;
	cin>>s;
	cout<<(s.length()==2?s[1]:*min_element(s.begin(),s.end()))<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}