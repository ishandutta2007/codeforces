#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <int> ans(n);
	ans[0] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] >= a[i - 1])
			ans[i] = ans[i - 1] + 1;
		else
			ans[i] = 1;
	}
	int answer = ans[0];
	for (int i = 1; i < n; i++)
		if (answer < ans[i])
			answer = ans[i];
	cout << answer;
	return 0;
}