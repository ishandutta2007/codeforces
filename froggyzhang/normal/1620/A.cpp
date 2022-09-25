#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	string s;
	int cnt=0;
	cin>>s;
	for(auto c:s)cnt+=c=='N';
	cout<<(cnt==1?"NO\n":"YES\n");	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}