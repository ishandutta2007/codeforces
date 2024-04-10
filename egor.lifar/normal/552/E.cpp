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
#include <cstring>
#include <cmath>


using namespace std;


long long get(string s) {
	int n = (int)s.size();
	long long k = s[0] - '0';
	int l = 1;
	while (l < n - 1) {
		//cout << l << ' '  << s << endl;
		if (s[l] == '+' && (l == n - 2 || s[l + 2] == '+')) {
			k += 1LL * (s[l + 1] - '0');
		} else {
			if (s[l] == '+') {
				l += 2;
				continue;
			}
			if (l == 1) {
				k -= 1LL * (s[0] - '0');
			}
			long long sum = (s[l - 1] - '0');
			while (l < n && s[l] == '*') {
				sum *= 1LL * (s[l + 1] - '0');
				l += 2;
			}
			if (s[l] == '*') {
				l += 2;
			}
			k += sum;
			continue;
		}
		l += 2;
	}
	return k;
}


int main() {
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') {
			v.push_back(i);
		}
	}
	if ((int)v.size() == 0) {
		cout << get(s) << endl;
		return 0;
	}
	//cout << get("8+7*6+5*4+3") << endl;
	long long sum = get(s);
	for (int j = 0; j < (int)v.size(); j++) {
		string s1;
		string s2;
		for (int g1 = 0; g1 < v[j]; g1++) {
			s1 += s[g1];
		}
		for (int g1 = v[j] + 1; g1 < n; g1++) {
			s2 += s[g1];
		}
		int l = v[j];
		long long k = 1;
		while (l > 1 && s[l - 2] == '*') {
			l-= 2;
			k *= 1LL * (s[l + 1] - '0');
		}
		k *= 1LL * (s[l - 1] - '0');
		if (l == 1) {
			sum = max(sum, get(s2) * k);
		} else {
			string s3;
			for (int j = 0; j < l - 2; j++) {
				s3 += s[j];
			}	
			sum = max(sum, get(s2) * k + get(s3));
		}
		l = v[j];
		k = 1;
		while (l < n - 1 && s[l + 2] == '*') {
			l += 2;
			k *= 1LL * (s[l - 1] - '0');
		}
		k *= 1LL * (s[l + 1] - '0');
		if (l == n - 2) {
			sum = max(sum, get(s1) * k); 
		} else {
			string s3;
			for (int j = l + 3; j < n; j++) {
				s3 += s[j];
			}	
			sum = max(sum, get(s1) * k + get(s3));
		}
		for (int j1 = j + 1; j1 < (int)v.size(); j1++) {
			l = v[j];
			k = 1;
			while (l > 1 && s[l - 2] == '*') {
				l-= 2;
				k *= 1LL * (s[l + 1] - '0');
			}
			k *= 1LL * (s[l - 1] - '0');
			int l1 = v[j1];
			long long k1 = 1;
			while (l1 < n - 1 && s[l1 + 2] == '*') {
				l1 += 2;
				k1 *= 1LL * (s[l1 - 1] - '0');
			}
			k1 *= 1LL * (s[l1 + 1] - '0');
			//cout << k << ' ' << k1 << endl;
			string s4;
			for (int g = v[j] + 1; g < v[j1]; g++) {
				s4 += s[g];
			}
			//cout << s4 << endl;
			long long sum1 = k * k1 * get(s4);
			//cout << get(s4) << endl;
			s4.clear();
			for (int g = 0; g < l - 2; g++) {
				s4 += s[g];
			}
			if (!s4.empty()) {
				sum1 += get(s4);
			}
			s4.clear();
			for (int g = l1 + 3; g < n; g++) {
				s4 += s[g];
			}
			if (!s4.empty()) {
				sum1 += get(s4);
			}
			sum = max(sum, sum1);
		}
	//	cout << sum << endl;
	}
	cout << sum << endl;
    return 0;
}