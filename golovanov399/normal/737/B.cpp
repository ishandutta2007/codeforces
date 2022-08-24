#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	ios_base::sync_with_stdio(0);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	string s;
	cin >> s;

	int cnt = 0;
	int cur = 0;
	s += '1';
	vector<int> ans;
	for (int i = 0; i <= n; ++i) {
		if (s[i] == '0') {
			cur += 1;
		} else {
			cnt += cur / b;
			cur = 0;
		}
		if (cur && cur % b == 0) {
			ans.push_back(i + 1);
		}
	}

	cout << cnt - (a - 1) << "\n";
	for (int i = 0; i < cnt - a + 1; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}