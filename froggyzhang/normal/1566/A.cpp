#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int n,s;
	cin>>n>>s;
	cout<<s/(n/2+1)<<'\n';	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}