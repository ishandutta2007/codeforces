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

int n;
int cnt[2];

int main() {
	fast;

	string s, r;
	cin >> s;

	reverse(s.begin(), s.end());

	int zero = 0;

	for(int i=0; i<s.size(); i++) {
		cnt[s[i] - '0']++;
		if(s[i] == '0') zero++, r+='0';
		else if(zero + 1 <= max(cnt[0], cnt[1])) {
			zero++;
			r += '0';
		}
		else {
			r += '1';
		}
	}

	reverse(r.begin(), r.end());

	cout << r;
}