#include <iostream>
#include <vector>
#include <iomanip>

#define endl '\n'
#define dl double long
#define fsp fixed << setprecision(11)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <dl> b(n);
	for (int i = 0; i < n; i++)
		b[i] = a[i];

	vector <pair <dl, int>> s;
	for (int i = n - 1; i >= 0; i--) {
		s.push_back({ b[i], 1 });
		for (int j = s.size() - 1; j >= 1; j--) {
			if (j == 0)
				break;
			if (s[j].first < s[j - 1].first)
				break;
			s[j - 1].first = (s[j - 1].first * s[j - 1].second + s[j].first * s[j].second) / (s[j - 1].second + s[j].second);
			s[j - 1].second = s[j - 1].second + s[j].second;
			s.resize(s.size() - 1);
		}
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		for (int j = 0; j < s[i].second; j++)
			cout << fsp << s[i].first << endl;
	}
	return 0;
}