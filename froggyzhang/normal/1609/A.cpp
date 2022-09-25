#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int n;
	cin>>n;
	int t=0,mx=0,sum=0;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		while(x%2==0)x>>=1,++t;
		mx=max(mx,x);
		sum+=x;
	}
	cout<<mx*(1LL<<t)+sum-mx<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}