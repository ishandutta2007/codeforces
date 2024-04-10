#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
void Solve(){
	cin>>n;
	cout<<(-n+1)<<' '<<n<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}