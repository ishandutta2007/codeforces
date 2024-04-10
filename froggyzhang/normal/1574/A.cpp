#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j)cout<<'(';
		for(int j=1;j<=i;++j)cout<<')';
		for(int j=1;j<=n-i;++j)cout<<'(';
		for(int j=1;j<=n-i;++j)cout<<')';
		cout<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}