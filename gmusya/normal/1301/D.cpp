#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'
#define ll long long

using namespace std;

int main() {
	ll n, m, k;
	vector <pair <ll, string>> answer;
	cin >> n >> m >> k;
	ll r = 4 * n * m - 2 * (n + m);
	if (k > r) {
		cout << "NO";
		return 0;
	}
	ll x = 1, y = 1;
	while (k > 0 && x <= n) {
		if (x % 2) {
			answer.push_back({ min(k, m - 1) , "R" });
			y = m;
			k -= min(k, m - 1);
		}
		else {
			answer.push_back({ min(k, m - 1), "L" });
			y = 1;
			k -= min(k, m - 1);
		}
		if (x == n)
			break;
		if (k > 0) {
			answer.push_back({ 1, "D" });
			x++;
			k--;
		}
	}
	while (k > 0 && x > 1) {
		if (x % 2) {
			while (k >= 3 && y > 1) {
				if (answer[answer.size() - 1].second == "UDL")
					answer[answer.size() - 1].first++;
				else
					answer.push_back({ 1, "UDL" });
				k -= 3;
				y--;
			}
			if (y > 1) {
				if (k == 1) 
					answer.push_back({ 1, "U" });
				if (k == 2)
					answer.push_back({ 1, "UD" });
				k = 0;
			}
			if (!k)
				break;
			answer.push_back({1, "U" });
			x--;
			k--;
		}
		else {
			while (k >= 3 && y < m) {
				if (answer[answer.size() - 1].second == "UDR")
					answer[answer.size() - 1].first++;
				else
					answer.push_back({ 1, "UDR" });
				k -= 3;
				y++;
			}
			if (y < m) {
				if (k == 1)
					answer.push_back({ 1, "U" });
				if (k == 2)
					answer.push_back({ 1, "UD" });
				k = 0;
			}
			if (!k)
				break;
			answer.push_back({ 1, "U" });
			x--;
			k--;
		}
	}
	if (k > 0)
		answer.push_back({ k, "L" });
	vector <pair <ll, string>> newanswer;
	for (int i = 0; i < answer.size(); i++)
		if (answer[i].first > 0)
			newanswer.push_back(answer[i]);
	cout << "YES" << endl;
	cout << newanswer.size() << endl;
	for (int i = 0; i < newanswer.size(); i++)
		cout << newanswer[i].first << " " << newanswer[i].second << endl;
	return 0;
}