#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int n,x,y,a,b;
	cin>>n>>x>>y;
	cin>>a>>b;
	int ans=0;
	for(int i=0;i<=min(n/2,x);++i){
		int j=min(n/2-i,y);
		ans=max(ans,i*a+j*b);
	}
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