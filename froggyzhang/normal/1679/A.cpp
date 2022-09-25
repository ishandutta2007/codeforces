#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
void Solve(){
	cin>>n;
	if(n<4||n&1){
		cout<<-1<<'\n';
		return;
	}
	cout<<(n-1)/6+1<<' '<<n/4<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}