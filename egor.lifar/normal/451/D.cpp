#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


string s;
int n;
long long ans, ans1;
int a, a1, b, b1;


int main() {
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			if (i % 2 == 0) {
				a++;
			} else {
				a1++;
			}
		}
		if (s[i] == 'b') {
			if (i % 2 == 0) {
				b++;
			} else {
				b1++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			if (i % 2 == 0) {
				ans += a1;
				ans1 += a;
				a--;
			} else {
				ans += a;
				ans1 += a1;
				a1--;
			}
		}
		if (s[i] == 'b') {
			if (i % 2 == 0) {
				ans += b1;
				ans1 += b;
				b--;
			} else {
				ans+= b;;
				ans1 += b1;
				b1--;
			}
		}
	}
	cout << ans << ' ' << ans1 << endl;
	return 0;
}