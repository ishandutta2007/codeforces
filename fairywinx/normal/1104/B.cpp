#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define int long long
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define mp make_pair

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
	ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	//srand(time(NULL));
}

const int N = 1e5 + 228;

pair<char, char> a[N];

signed main() {
   	setup();

	string s;
	cin >> s;
	vector<char> a;
	int ans = 0;
	for(int i = 0; i < s.size(); ++i) {
		if (a.size() == 0)
			a.pb(s[i]);
		else {
			if (a.back() == s[i]) {
				++ans;
				a.pop_back();
			}
			else 
				a.push_back(s[i]);
		}
	}
	if (ans % 2 == 1)
		cout << "YES";
	else
		cout << "NO";
}