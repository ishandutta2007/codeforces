#include <cstdio>
#include <cstring>

#include <algorithm>
#include <map>
#include <iostream>
#include <bitset>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

int n, mC;
string s, ans;
map<string, int> mp;

int main() {
	cin >> n >> s;
	for (int i = 0; i + 1 < n; ++i)
		if (++mp[s.substr(i, 2)] > mC) {
			ans = s.substr(i, 2);
			mC = mp[s.substr(i, 2)];
		}
	cout << ans << endl;
	return 0;
}