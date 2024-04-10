#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int DIGS[] = {1, 6, 8, 9};

int dfs(int cur, int used, int mod) {
	if(used == (1 << 4) - 1) {
		if(cur % 7 == mod) return cur;
		else return -1;
	}
	for(int i = 0; i < 4; i++) {
		if(used & (1 << i)) continue;
		int res = dfs(cur * 10 + DIGS[i], used | (1 << i), mod);
		if(res >= 0) return res;
	}

	return -1;
}

pair<int, string> go(string s) {
	int cnt[20];
	for(int i = 0; i < 10; i++) cnt[i] = 0;
	for(int i = 0; i < s.size(); i++) {
		cnt[s[i] - '0'] ++;
	}

	for(int i = 0; i < 4; i++) {
		cnt[DIGS[i]] --;
	}

	s.clear();
	int mod = 0;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < cnt[i]; j++) s.push_back(char(i + '0'));
	}

	reverse(s.begin(), s.end());

	for(int i = 0, pow = 2; i < s.size(); i++, pow *= 5, pow %= 7) {
		mod += (s[i] - '0') * pow;
		mod %= 7;
	}

	return make_pair(dfs(0, 0, mod), s);
}

int main() {
	string s;
	cin >> s;

	pair<int, string> res = go(s);

	cout << res.first << res.second << '\n';
}