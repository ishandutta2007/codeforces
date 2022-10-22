#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0)
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pre(a) cout<<fixed; cout.precision(a);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF = 1e18;
const int inf = 1e9;

int n, ans;
int a[111];
int b[111];
string s;

int main() {
	fast;

	cin >> n;
	cin >> s;

	for(int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
	}
	
	for(int i=1; i<=10000; i++) {
		int cnt = 0;
		
		for(int j=0; j<s.size(); j++) {
			if(s[j] == '1') cnt++;
		}

		ans = max(ans, cnt);

		for(int j=0; j<n; j++) {			
			if(i>=b[j] && (i - b[j]) % a[j] == 0) {
				s[j] = '1' + '0' - s[j];
			}
		}
	}

	cout << ans;
}