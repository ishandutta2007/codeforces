#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		ll x;
		cin>>x;
		cout<<(x>=15&&x%14<=6&&x%14>=1?"YES\n":"NO\n");
	}
	return 0;
}