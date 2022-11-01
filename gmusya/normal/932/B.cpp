#include <iostream>
#include <vector>

using namespace std;

int mult(int n) {
	int ans = 1;
	while (n > 0) {
		if (n % 10 > 0)
			ans *= n % 10;
		n /= 10;
	}
	return ans;
}

int main() {
	vector <int> answer(1e6	 + 2);
	for (int i = 1; i < 10; i++)
		answer[i] = i;
	for (int i = 10; i < answer.size(); i++)
		answer[i] = answer[mult(i)];
	vector <vector <int>> query(1e6 + 2, vector<int>(10));
	for (int i = 1; i < answer.size(); i++) {
		query[i] = query[i - 1];
		query[i][answer[i]]++;
	}
	int m;
	cin >> m;
	while (m--) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << query[r][k] - query[l - 1][k] << endl;
	}
}