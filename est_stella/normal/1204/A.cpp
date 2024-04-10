#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define INF 1e18
#define inf 1e9
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

int ans;

int main() {
	fast;

	string s;
	cin >> s;

	if(s[0] == 0) {
		cout << 0;
		return 0;
	}

	ans = (s.size()-1)/2+1;

	if(s.size() % 2 == 0) {
		cout << ans;
		return 0;
	}

	for(int i=s.size()-1; i>=2; i-=2) {
		if(s[i] != '0' || s[i-1] != '0') {
			cout << ans;
			return 0;
		}
	}

	cout << ans - 1;
}