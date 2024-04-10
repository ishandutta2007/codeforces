#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<((a+b+c)%3?1:0)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}