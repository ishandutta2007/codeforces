#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;

map<string, int> mp;

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		ll ans = 0;
		for (int i = 1; i <= n; i++){
			string s; cin >> s;
			for (char ch = 'a'; ch <= 'k'; ch++){
				string str = s; str[0] = ch;
				if (str != s && mp.count(str) != 0){ ans += mp[str]; }
				str = s; str[1] = ch;
				if (str != s && mp.count(str) != 0){ ans += mp[str]; }
			}
			mp[s] += 1;
		}
		cout << ans << endl;
		mp.clear();
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}