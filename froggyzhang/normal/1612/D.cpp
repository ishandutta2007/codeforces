#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	ll a,b,x;
	cin>>a>>b>>x;
	if(x>max(a,b)){
		cout<<"NO\n";
		return;
	}
	while(b){
		if(a<b){
			swap(a,b);
			continue;
		}
		if(x<=a&&x%b==a%b){
			cout<<"YES\n";
			return;
		}
		a%=b;
	}
	cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}