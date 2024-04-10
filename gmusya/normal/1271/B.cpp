#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <char> a(n);
	vector <int> answer;	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int cntW = 0, cntB = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 'W')
			cntW++;
		else
			cntB++;
	}
	if (cntW % 2 == 0) {
		for (int i = 0; i < n - 1; i++) 
			if (a[i] == 'W') {
				answer.push_back(i);
				a[i] = 'B';
				if (a[i + 1] == 'W')
					a[i + 1] = 'B';
				else
					a[i + 1] = 'W';
			}
		cout << answer.size() << endl;
		for (auto now : answer)
			cout << now + 1 << " ";
		return 0;
	}
	if (cntB % 2 == 0) {
		for (int i = 0; i < n - 1; i++)
			if (a[i] == 'B') {
				answer.push_back(i);
				a[i] = 'W';
				if (a[i + 1] == 'W')
					a[i + 1] = 'B';
				else
					a[i + 1] = 'W';
			}
		cout << answer.size() << endl;
		for (auto now : answer)
			cout << now + 1 << " ";
		return 0;
	}
	cout << -1;
	return 0;
}