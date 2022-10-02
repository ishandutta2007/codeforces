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


#define M 1000000007


int n;
string s;
map<char, long long> m;
bool used[100000];


int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		m[s[i]]++;
	}
	long long p = 0;
	for (char c = 'A'; c <= 'Z'; c++) {
		if (m[c] != 0) {
			p = max(p, m[c]);
		}
	}
	long long k = 0;
	for (char c = 'A'; c <= 'Z'; c++) {
		if (m[c] == p) {
			k++;
		}
	}
	//cout << k << endl;
	long long k1 = k;
	for (long long i = 2; i <= n; i++) {
		k *= k1;
		k %= M;
	}
	cout << k << endl;
    return 0;
}