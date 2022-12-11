#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
int a[100007];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n;
		int s = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			s ^= a[i];
		}
		if (s == 0) {
			cout << "DRAW\n";
			continue;
		}
		int v = -1;
		for (int i = 31; i >= 0; --i) {
			if ((s >> i) & 1) {
				v = i;
				break;
			}
		}
		int w1 = 0, w2 = 0;
		for (int i = 0; i < n; ++i) {
			if ((a[i] >> v) & 1) {
				++w1;
			} else {
				++w2;
			}
		}

		int c1 = ((w1 - 1) / 2) % 2;
		int c2 = w2 % 2;

		if (c1 == 0 && c2 == 0) {
			cout << "WIN\n";
		}
		if (c1 == 0 && c2 == 1) {
			cout << "WIN\n";
		}
		if (c1 == 1 && c2 == 0) {
			cout << "LOSE\n";
		}
		if (c1 == 1 && c2 == 1) {
			cout << "WIN\n";
		}
	}
}