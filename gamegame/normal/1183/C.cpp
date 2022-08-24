#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k,n,a,b;
void solve(){
	cin >> k >> n >> a >> b;
	a-=b;
	k-=n*b;
	if(k<=0){
		cout << "-1\n";
		return;
	}
	cout << min(n,(k-1)/a) << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    int t;cin >> t;while(t--) solve();
}