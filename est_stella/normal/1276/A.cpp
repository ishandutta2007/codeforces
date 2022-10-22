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

int main() {
	fast;

	int t;
	cin >> t;

	while(t--) {
		vector<int> one, two, twone;
		string s;
		cin >> s;

		for(int i=2; i<s.size(); i++) {
			string s2;
			for(int j=i-2; j<=i; j++) {
				s2 += s[j];
			}

			if(s2 == "one") one.pb(i);
			if(s2 == "two")	two.pb(i);

			s2.clear();
			if(i < 4) continue;
			for(int j=i-4; j<=i; j++) {
				s2 += s[j];
			}

			if(s2 == "twone") twone.pb(i-1), one.pop_back(), two.pop_back();
		}

		cout << one.size() + two.size() + twone.size() << "\n";
		for(auto i : one) cout << i << " ";
		for(auto i : two) cout << i << " ";
		for(auto i : twone) cout << i << " ";
		cout << "\n";
	}
}