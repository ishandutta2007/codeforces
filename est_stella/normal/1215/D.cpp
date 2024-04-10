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

int n;
string s;
int cnt1, sum1, cnt2, sum2;

int main() {
	fast;

	cin >> n;
	cin >> s;

	for(int i=0; i<n/2; i++) {
		if(s[i] == '?') cnt1++;
		else sum1 += s[i] - '0';
	}

	for(int i=n/2; i<n; i++) {
		if(s[i] == '?') cnt2++;
		else sum2 += s[i] - '0';
	}

	if((cnt2 - cnt1) / 2 * 9 == sum1 - sum2) {
		cout << "Bicarp";
	}
	else {
		cout << "Monocarp";
		//cout << " " << (cnt2 - cnt1) / 2 * 9 << " " << sum2 - sum1;
	}
}