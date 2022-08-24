#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n;
set<int>s;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;s.insert(x);
	}
	while(true){
		auto it=s.end();--it;
		ll cur=*it;
		ll fun=cur;
		while(s.find(fun)!=s.end()) fun/=2;
		if(fun==0){
			for(auto c:s) cout << c << ' ';
			cout << '\n';
			return 0;
		}
		s.erase(cur);s.insert(fun);
	}
}