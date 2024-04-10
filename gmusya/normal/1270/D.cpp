#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	n = k + 1;
	vector <int> answer;
	for (int i = 0; i < n; i++) {
		int pos, val;
		cout << "? ";
		for (int j = i; j < i + k; j++)
			cout << j % n + 1 << " ";
		cout << endl;
		cout.flush();
		cin >> pos >> val;
		answer.push_back(val);
	}
	int ma = answer[0];
	for (int i = 0; i < n; i++)
		if (ma < answer[i])
			ma = answer[i];
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (ma == answer[i])
			cnt++;
	cout << "! " << cnt;
	return 0;
}