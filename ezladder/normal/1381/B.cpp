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
int a[4444];
bool can[4444];

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
		cin >> n; n *= 2;
		for (int i = 0; i < n; ++i) cin >> a[i];
		vector<int> len;
		int last = n;
		while (last > 0) {
			int ma = 0;
			for (int i = 0; i < last; ++i) {
				if (a[ma] < a[i]) ma = i;
			}
			len.pb(last - ma);
			last = ma;
		}
	
		int sum = 0;
		for (int x : len) sum += x;
		assert(sum == n);

		int need = n >> 1;
		for (int i = 0; i <= need; ++i) can[i] = 0;
		can[0] = 1;
		for (int x : len) {
			for (int i = need; i >= x; --i) {
				if (can[i - x]) can[i] = 1;
			}
		}
		if (can[need]) cout << "YES\n"; else cout << "NO\n";
	}
}