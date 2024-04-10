#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c;
void Solve(){
	cin>>a>>b>>c;
	cout<<((a+2LL*b+3LL*c)&1)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}