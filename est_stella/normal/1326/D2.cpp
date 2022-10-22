#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;
const ll Mod = 998244353;

int a[3000010];

void solve() {
	string s, t;
	cin >> s;

	for(int i=0; i<s.size(); i++) {
		t += '*';
		t += s[i];
	}
	t += '*';
	
	int n = t.size();

	for(int i=0; i<n; i++) a[i] = 0;

	int r = 0, p = 0;
	for(int i=0; i<n; i++) {
		if(i <= r)
			a[i] = min(a[2*p-i], r-i);
		else 
			a[i] = 0;

		while(i - a[i] - 1 >= 0 && i + a[i] + 1 < n && t[i - a[i] - 1] == t[i + a[i] + 1]) a[i]++;

		if(r < i + a[i]) {
			r = i + a[i]; 
			p = i;
		}
	}

	int l = 0;
	for(int i=0; i < n-i-1; i++) {
		if(t[i] == t[n-i-1]) l++;
		else break;
	}

	int mx = 0, mxi = l;
	for(int i=l; i<n-l; i++) {
		if(i - a[i] <= l || i + a[i] >= n - l - 1) {
			if(min(i - l, n - l - i - 1) > mx) {
				mx = min(i - l, n - l - i - 1);
				mxi = i;
			}
		}
	}

	string ans;
	for(int i=0; i<l; i++) {
		if(t[i] != '*') ans += t[i];
	}

	for(int i = mxi - mx; i<= mxi + mx; i++) {
		if(t[i] != '*') ans += t[i];
	}

	for(int i = n-l; i<n; i++) {
		if(t[i] != '*') ans += t[i];
	}

	cout << ans << "\n";
}

int main() {
	fast;

	int t;
	cin >> t;

	while(t--) {
		solve();
	}
}