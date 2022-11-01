#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> w(n), ans;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	map <int, int> in, ex;
	for (int i = 0; i < n; i++)
		in[w[i]] = i + 1;
	vector <char> c(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		cin >> c[i];
		if (c[i] == '1') {
			cout << (--ex.end())->second << " ";
			ex.erase(--ex.end());
		}
		if (c[i] == '0') {
			cout << (in.begin())->second << " ";
			ex.insert({ in.begin()->first, in.begin()->second });
			in.erase(in.begin());
		}
	}
	return 0;
}