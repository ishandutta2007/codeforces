#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int copy_n = n, cnt = 0, min_c = 10, first_c;
		int tf = 1;
		while (copy_n > 0) {
			min_c = min(min_c, copy_n % 10);
			cnt++;
			if (copy_n < 10)
				first_c = copy_n;
			copy_n /= 10;
		}
		copy_n = n;
		while (copy_n > 0) {
			if (copy_n % 10 > first_c)
				tf = 2;
			if (copy_n % 10 < first_c)
				tf = 0;
			copy_n /= 10;
		}
		int answer;
		if (n >= 100)
			answer = 9 + (cnt - 2) * 9 + first_c - (tf == 0);
		else
			if (n >= 10)
				answer = answer = 9 + (cnt - 2) * 9 + first_c - (tf == 0);
			else
				answer = n;
		cout << answer << endl;
	}
	return 0;
}