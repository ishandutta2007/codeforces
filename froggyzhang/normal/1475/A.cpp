#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=60;++i){
		s.insert(1LL<<i);
	}
	int T;
	cin>>T;
	while(T--){
		ll x;
		cin>>x;
		cout<<(s.count(x)?"No\n":"Yes\n");
	}
	return 0;
}