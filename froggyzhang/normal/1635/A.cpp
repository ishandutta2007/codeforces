#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void Solve(){
	cin>>n;
	int ans=0,x;
	while(n--)cin>>x,ans|=x;
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}