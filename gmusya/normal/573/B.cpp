#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n + 2);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector <int> ans(n + 2);
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		tmp = min(tmp, a[i] - i);
		ans[i] = i + tmp;
	}
	tmp = n + 1;
	for (int i = n; i >= 1; i--) {
		tmp = min(tmp, a[i] + i);
		ans[i] = min(ans[i], tmp - i);
	}
	int answer = 0;
	for (int i = 1; i <= n; i++)
		answer = max(answer, ans[i]);
	cout << answer;
	return 0;
}