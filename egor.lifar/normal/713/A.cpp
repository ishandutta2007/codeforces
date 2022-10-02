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
#include <queue>
#include <unordered_map>


using namespace std;


int t;
unordered_map<string, int> m;


string getnorm(long long x) {
	string a;
	for (int i = 0; i < 19; i++) {
		a += '0' + (x % 10L) % 2LL;
		x /= 10LL;
	}
	reverse(a.begin(), a.end());
	return a;
}


string getnorm(string a) {
	reverse(a.begin(), a.end());
	for (int i = (int)a.size(); i < 19; i++) {
		a += '0';
	}
	reverse(a.begin(), a.end());
	return a;
}


void Add(long long x) {
	m[getnorm(x)]++;
}


void Delete(long long x) {
	m[getnorm(x)]--;
}


int Query(string x) {
	return m[getnorm(x)];
}



int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		if (s == "+") {
			long long x;
			scanf("%lld", &x);
			Add(x);
		} else {
			if (s == "-") {
				long long x;
				scanf("%lld", &x);
				Delete(x);
			} else {
				string s1;
				cin >> s1;
				printf("%d\n", Query(s1));
			}
		}
	}
    return 0;
}