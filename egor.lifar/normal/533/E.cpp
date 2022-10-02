#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set> 


using namespace std;


int n;
string s, s1;
map<char, int> m, m1;


int main() {
	cin >> n;
	cin >> s >> s1;
	for (int i = 0; i < n; i++) {
		m[s[i]]++;
		m1[s1[i]]++;
	}
	int k = 0;
	int k1 = 0;
	for (char i = 'a'; i <= 'z'; i++) {
		if (m[i]) {
			k++;
		}
		if (m1[i]) {
			k1++;
		}
	}
	if (abs(k - k1) > 1) {
		cout << 0 << endl;
		return 0;
	}
	string s2;
	string s3;
	for (int i = 0; i < n; i++) {
		if (s[i] != s1[i]) {
			for (int j = 0; j < n; j++) {
				if (j < i) {
					s2 += s[j];
					continue;
				}
				if (j == i) {
					s2 += s1[i];
				}
				s2 += s[j];
			}
			for (int j = 0; j < n; j++) {
				if (j < i) {
					s3 += s1[j];
					continue;
				}
				if (j == i) {
					s3 += s[i];
				}
				s3 += s1[j];
			}
			break;
		}
	}
//	cout << s2 << ' ' << s3 << endl;
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (i == n || s1[i] != s2[i]) {
			if (i == n) {
				ans++;
				break;
			}
			bool b = true;
			//cout << s << endl;
			for (int j = i + 1; j <= n; j++) {
				if (s2[j] != s1[j - 1]) {
					b = false;
					break;
				}
			}
			if (b) {
				ans++;
			}
			break;
		}
	}
	for (int i = 0; i <= n; i++) {
		if (i == n || s[i] != s3[i]) {
			if (i == n) {
				ans++;
				break;
			}
			bool b = true;
			for (int j = i + 1; j <= n; j++) {
				if (s3[j] != s[j - 1]) {
					b = false;
					break;
				}
			}
			if (b) {
				ans++;
			}
			break;
		}
	}
	cout << ans << endl;
    return 0;
}