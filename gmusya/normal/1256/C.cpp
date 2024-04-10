#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, d;
	cin >> n >> m >> d;
	vector <int> a(m);
	for (int i = 0; i < m; i++)
		cin >> a[i];
	vector <int> sum(m);
	sum[0] = a[0];
	for (int i = 1; i < m; i++)
		sum[i] = sum[i - 1] + a[i];
	if (sum[m - 1] + (d - 1) * (m + 1) < n) {
		cout << "NO";
		return 0;
	}
	cout << "YES";
	vector <int> answer;
	int cnt = 1;
	d--;
	for (int i = 0; i < d; i++)
		answer.push_back(0);
	cout << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < a[i]; j++)
			answer.push_back(i + 1);
		for (int j = 0; j < d; j++)
			answer.push_back(0);
	}
	int i = answer.size() - 1;
	while (answer.size() > n) {
		if (answer[i] == 0) 
			answer.erase(answer.begin() + i);
		i--;
	}
	for (auto now : answer)
		cout << now << " ";
	return 0;
}