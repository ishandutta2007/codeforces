#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(pair <string, int> a, pair <string, int> b) {
	return a.first.size() < b.first.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int sz = 2 * (n - 1);
	vector <pair <string, int>> s(2 * (n - 1));
	for (int i = 0; i < sz; i++) {
		cin >> s[i].first;
		s[i].second = i;
	}
	sort(s.begin(), s.end(), cmp);
	{
		bool tf = true;
		vector <char> ans(sz, 'N');
		string L = s[sz - 2].first, R = s[sz - 1].first;
		string t = L[0] + R;
		for (int i = 0; i < sz; i++) {
			if (i % 2 && s[i].first == s[i - 1].first) {
				ans[s[i].second] = 'P';
				continue;
			}
			int x = s[i].first.size();
			string tmp = t.substr(0, x);
			if (tmp == s[i].first) ans[s[i].second] = 'P';
			tmp = t.substr(n - x, x);
			if (tmp == s[i].first) ans[s[i].second] = 'S';
		}
		for (int i = 0; i < sz; i++)
			if (ans[i] == 'N')
				tf = false;
		if (tf) {
			for (int i = 0; i < sz; i++) cout << ans[i];
			return 0;
		}
	}
	{
		bool tf = true;
		vector <char> ans(sz, 'N');
		string L = s[sz - 2].first, R = s[sz - 1].first;
		string t = L + R[n - 2];
		for (int i = 0; i < sz; i++) {
			if (i % 2 && s[i].first == s[i - 1].first) {
				ans[s[i].second] = 'P';
				continue;
			}
			int x = s[i].first.size();
			string tmp = t.substr(0, x);
			if (tmp == s[i].first) ans[s[i].second] = 'P';
			tmp = t.substr(n - x, x);
			if (tmp == s[i].first) ans[s[i].second] = 'S';
		}
		for (int i = 0; i < sz; i++)
			if (ans[i] == 'N')
				tf = false;
		if (tf) {
			for (int i = 0; i < sz; i++) cout << ans[i];
			return 0;
		}
	}
	{
		bool tf = true;
		vector <char> ans(sz, 'N');
		string L = s[sz - 2].first, R = s[sz - 1].first;
		string t = R + L[n - 2];
		for (int i = 0; i < sz; i++) {
			if (i % 2 && s[i].first == s[i - 1].first) {
				ans[s[i].second] = 'P';
				continue;
			}
			int x = s[i].first.size();
			string tmp = t.substr(0, x);
			if (tmp == s[i].first) ans[s[i].second] = 'P';
			tmp = t.substr(n - x, x);
			if (tmp == s[i].first) ans[s[i].second] = 'S';
		}
		for (int i = 0; i < sz; i++)
			if (ans[i] == 'N')
				tf = false;
		if (tf) {
			for (int i = 0; i < sz; i++) cout << ans[i];
			return 0;
		}
	}
	{
		bool tf = true;
		vector <char> ans(sz, 'N');
		string L = s[sz - 2].first, R = s[sz - 1].first;
		string t = R[0] + L;
		for (int i = 0; i < sz; i++) {
			if (i % 2 && s[i].first == s[i - 1].first) {
				ans[s[i].second] = 'P';
				continue;
			}
			int x = s[i].first.size();
			string tmp = t.substr(0, x);
			if (tmp == s[i].first) ans[s[i].second] = 'P';
			tmp = t.substr(n - x, x);
			if (tmp == s[i].first) ans[s[i].second] = 'S';
		}
		for (int i = 0; i < sz; i++)
			if (ans[i] == 'N')
				tf = false;
		if (tf) {
			for (int i = 0; i < sz; i++) cout << ans[i];
			return 0;
		}
	}
	return 0;
}