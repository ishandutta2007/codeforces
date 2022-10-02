#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>


using namespace std;


#define INF 30000000000LL


int n, k;
long long a[300002];
bool b[300002];


int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		if (s == "?") {
			b[i] = true;
		} else {
			int t = 0;
			if (s[0] == '-') {
				t = 1;
			}
			for (int j = t; j < (int)s.size(); j++) {
				a[i] *= 10LL;
				a[i] += s[j] - '0';
			}
			if (t) {
				a[i] *= -1LL;
			}
		}
	}
	a[0] = -INF - 1;
	for (int i = n + 1; i <= 3 * n; i++) {
		a[i] = INF + 1LL;
	}
	for (int i = 1; i <= k; i++) {
		int g = i;
		for (int j = i; j <= n + k; j+= k) {
			if (!b[j] && j != g) {
				if (a[j] <= a[g] && j <= n && !b[g]) {
					cout << "Incorrect sequence" << endl;
					return 0;
				}
				//cout << j << endl;
				if (b[g]) {
						if (a[j] >= 0LL) {
							vector<int> v;
								vector<int> v1;
								long long t = (min(j, n) - g) / k + 1;
								for (int g1 = 0; g1 <= t && (int)v.size() + (int)v1.size() < t; g1++) {
									if (g1 == 0) {
										v1.push_back(0);
									} else {
										if (g1 < a[j]) {
											v1.push_back(g1);
										}
										if ((int)v.size() + (int)v1.size() == t) {
											break;
										}
										v.push_back(-g1);
									}
								}
								int l = 0;
								for (int g1 = g; g1 < j; g1+= k) {
									if ((int)v.size() > 0) {
										a[g1] = v.back();
										v.pop_back();
									} else {
										a[g1] = v1[l];
										l++;
									}
								}
						} else {
							for (int g1 = j - k; g1 >= g; g1 -= k) {
								a[g1] = a[g1 + k] - 1LL;
							}
						}
				} else {
					if (a[j] - a[g] - 1LL < (long long)(j - g - 1LL) / (long long)k && j <= n) {
						cout << "Incorrect sequence" << endl;
						return 0;
					}
					if (j != g + k) {
						if (a[g] >= 0LL && a[j] >= 0LL) {
							for (int g1 = g + k; g1 < j; g1 += k) {
								a[g1] = a[g1 - k] + 1LL;
							}  
						} else {
							if (a[j] >= 0LL) {
								vector<int> v;
								vector<int> v1;
								long long t = (min(j, n) - g) / k;
								for (int g1 = 0; g1 <= t && (int)v.size() + (int)v1.size() < t; g1++) {
									if (g1 == 0) {
										v1.push_back(0);
									} else {
										if (g1 < a[j]) {
											v1.push_back(g1);
										}
										if ((int)v.size() + (int)v1.size() == t) {
											break;
										}
										if (-g1 > a[g]) {
											v.push_back(-g1);
										}
									}
								}
								int l = 0;
								for (int g1 = g + k; g1 < j; g1+= k) {
									if ((int)v.size() > 0) {
										a[g1] = v.back();
										v.pop_back();
									} else {
										a[g1] = v1[l];
										l++;
									}
								}
							} else {
								for (int g1 = j - k; g1 > g; g1 -= k) {
									a[g1] = a[g1 + k] - 1LL;
								}
							}
						}
 					}
 				}
				g = j;
			}
			if (!b[j]) {
				g = j;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl; 
    return 0;
}