#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);
const long long mdl = 1000 * 1000 * 1000 + 7;
const int size = 1000;
long long pw[size];

int main() {
	pw[0] = 1;
	for (int i = 1; i < size; i++)
		pw[i] = (pw[i - 1] * 2) % mdl;

	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	string str;
	cin >> str;
	int n = str.length();
	long long ans = 0;
	reverse(str.begin(), str.end());
	for (int i = 0; i < n; i++)
		if (str[i] == '1') {
			ans = (ans + ((pw[i] * pw[i]) % mdl) * pw[n - i - 1] % mdl) % mdl;
		}

	cout << ans << endl;

	return 0;
}