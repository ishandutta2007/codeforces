#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
#define fi first
#define se second
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	map<int,int>mp;
	for(int i=1; i<=n ;i++){
		for(int j=i+1; j<=n ;j++){
			mp[a[j]-a[i]]++;
		}
	}
	cout << mp.size() << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}