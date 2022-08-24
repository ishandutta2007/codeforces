#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
#define fi first
#define se second
const int N=2001;
const ll mod=998244353;
ll a[N],b[N];
int n,m;

//<edge>
//</groups>
bool can[1000];
bool isp[1000];
void solve(){
	string s;
	int n;cin >> n;
	cin >> s;
	s='?'+s;
	for(int i=1; i<=n/2 ;i++){
		if(s[i]=='0'){
			cout << i << ' ' << n << ' ' << i+1 << ' ' << n << '\n';
			return;
		}
		if(s[n+1-i]=='0'){
			cout << 1 << ' ' << n+1-i << ' ' << 1 << ' ' << n-i << '\n';
			return;
		}
	}
	cout << 1 << ' ' << (n+1)/2 << ' ' << n/2+1 << ' ' << n << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}