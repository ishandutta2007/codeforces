#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s = "codeforces";
	long long k;
	cin >> k;
	long long first = 2;
	long long cnt = 0;
	long long ans;
	for (;; first++) {
		for (cnt = 0; cnt <= 9; cnt++) {
			ans = 1;
			for (long long j = 0; j < cnt; j++)
				ans *= first;
			for (long long j = cnt; j < 10; j++)
				ans *= (first - 1);
			if (ans >= k) break;
		}
		if (ans >= k) break;
	}
	for (long long i = 0; i < 10; i++) {
		if (i < cnt) for (long long j = 0; j < first; j++) cout << s[i];
		else for (long long j = 1; j < first; j++) cout << s[i];
	}
	return 0;
}