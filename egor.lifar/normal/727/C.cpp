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


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()


int n;
int sum[5001];
int ans[5001];


int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cout << "?" << ' ' << 1 << ' ' << i + 1 << endl;
		scanf("%d", &sum[i]);
	}
	cout << "?" << ' ' << n - 1 << ' ' << n << endl;
	int s1;
	scanf("%d", &s1);
	ans[n - 1] = (sum[n - 1] - sum[n - 2] + s1) / 2;
	ans[0] = sum[n - 1] - ans[n - 1];
	for (int i = 1; i < n - 1; i++) {
		ans[i] = sum[i] - ans[0];
	}
	cout << "!";
	for (int i = 0; i < n; i++) {
		cout << ' ' << ans[i];
	}
	cout << endl;
	return 0;
}