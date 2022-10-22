#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define pre(a) cout<<fixed; cout.precision(a)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int n;
string s;

bool f(string t) {
	int sum = 0, zero = 0, even = 0;
	for(int i=0; i<t.size(); i++) {
		sum += t[i] - '0';
		if(t[i] == '0') zero++;
		if((t[i] - '0') % 2 == 0) even++;
	}

	return (zero >= 1 && even >= 2 && sum % 3 == 0);
}

int main() {
	fast;

	cin >> n;

	for(int i=0; i<n; i++) {
		cin >> s;

		if(f(s)) cout << "red\n";
		else cout << "cyan\n";
	}
}