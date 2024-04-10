#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s[1] == '+')
			cnt++;
		else
			cnt--;
	}
	cout << cnt;
	return 0;
}