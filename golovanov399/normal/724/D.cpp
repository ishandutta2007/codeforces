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

bool is_ok(const string& s, char mxc, int m) {
	int lst = -1;
	for (itn i = 0; i < (int)s.length(); i++) {
		if (s[i] <= mxc) {
			lst = i;
		}
		if (i - lst >= m) {
			return false;
		}
	}
	return true;
}

int main(){

	int m = nxt();
	string s;
	cin >> s;
	int n = s.length();
	
	int mxc = 'z';
	while (is_ok(s, mxc, m)) {
		mxc--;
	}
	mxc++;
	
	vector<int> ans(26);
	vector<int> mx(n + 1);
	multiset<int> S;
	S.insert(0);
	for (int i = 0; i < n; i++) {
		if (s[i] < mxc) {
			ans[s[i] - 'a'] += 1;
			mx[i + 1] = *S.begin();
		} else if (s[i] == mxc) {
			mx[i + 1] = *S.begin() + 1;
		} else {
			mx[i + 1] = 1e9;
		}
		if (i >= m - 1) {
			S.erase(S.find(mx[i - m + 1]));
		}
		S.insert(mx[i + 1]);
	}

	ans[mxc - 'a'] = *S.begin();

	for (int i = 0; i < 26; i++) {
		cout << string(ans[i], 'a' + i);
	}

	cout << "\n";

	return 0;
}