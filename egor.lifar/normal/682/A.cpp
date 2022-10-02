#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>


using namespace std;


int n, m;
int cnt[5], cnt1[5];


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cnt[i % 5]++;
	}
	for (int i = 1; i <= m; i++) {
		cnt1[i % 5]++;
	}
	long long ans = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if ((i + j) % 5 == 0) {
				ans += 1LL * cnt[i] * cnt1[j];
			}
		}
	}
	cout << ans << endl;
    return 0;
}