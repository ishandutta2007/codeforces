#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>


using namespace std;


#define sz(c) (long long)(c).size()
#define all(c) (c).begin(), (c).end()


int main() {
	string s;
	cin >> s;
	long long l = 0;
	long long ans = 0;
	for (long long i = 0; i < sz(s); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			continue;
		}	
		if (s[i] == '.') {
			continue;
		}		
		l = max(l, i);
		if (l > i) {
			continue;
		}
		long long cost = s[i] - '0';
		while (l + 1 < sz(s) && ((s[l + 1] >= '0' && s[l + 1] <= '9') || s[l + 1] == '.')) {
			if (s[l + 1] != '.') {
				cost *= 10;
				cost += s[l + 1] - '0';
			}
			l++;
		}
		if (l >= i + 3 && (s[l] >= '0' && s[l] <= '9') && (s[l - 1] >= '0' && s[l - 1] <= '9')) {
			if (s[l - 2] != '.') {
				cost *= 100;
			}
		} else {
			cost *= 100;
		}
		l++;
		ans += cost;
	}
	string a;
	while (ans != 0) {
		a += char(ans % 10 + '0');
		ans /= 10;
	}	
	string b;
	for (long long i = 0; i < (long long)a.size(); i++) {
		b += a[i];
		if (i == 1) {
			b += '.';
		} else {
			if ((i - 1) % 3 == 0 && i != (long long)a.size() - 1) {
				b += '.';
			}
		}
	}
	long long t = 0;
	//cout << b << endl;
	if ((long long)b.size() >= 3 && b[0] == '0' && b[1] == '0' && b[2] == '.') {
		t = 3;
	} else {
		if ((long long)b.size() <= 3) {
			if ((long long)b.size() == 2) {
				b += '.';
				b += '0';
			} else {
				if ((long long)b.size() == 1) {
					b += '0';
					b += '.';
					b += '0';
				} else {
					b += '0';
				}
			}
		}
	}
	for (long long i = (long long)b.size() - 1; i >= t; i--) {
		printf("%c", b[i]);
	}
	printf("\n");
	return 0;
}