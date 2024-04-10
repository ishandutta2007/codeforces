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



int c[26];
int n;
string s;
long long sum[100000];
map<long long, long long> m[26];


int main() {
	for (int i = 0; i < 26; i++) {
		cin >> c[i];
	}
	cin >> s;
	n = (int)s.size();
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		sum[i] = (i > 0 ? sum[i - 1]: 0) + c[s[i] - 'a'];
		if (i > 0) {
			ans += m[s[i] - 'a'][(i > 0 ? sum[i - 1]: 0LL)];
		}
		m[s[i] - 'a'][sum[i]]++;
	}
	cout << ans << endl;
    return 0;
}