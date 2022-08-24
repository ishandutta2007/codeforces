#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int>p,q;
ll ask(){
	cout << p.size() << ' ' << q.size();
	for(auto c:p) cout << ' ' << c;
	for(auto c:q) cout << ' ' << c;
	cout << endl;
	ll res;cin >> res;
	return res;
}
void solve(){
	cin >> n;
	ll ans=0;
	for(int i=0; (1<<i)<n ;i++){
		p.clear();q.clear();
		for(int j=0; j<n ;j++){
			if(j&(1<<i)) q.push_back(j+1);
			else p.push_back(j+1);
		}
		ans=max(ans,ask());
	}
	cout << "-1 " << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
	
}