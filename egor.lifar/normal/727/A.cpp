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


int a, b;


int main() {
	cin >> a >> b;
	vector<int> ans;
	while (a < b) {
		ans.push_back(b);
		if (b % 10 == 1) {
			b /= 10;
		} else {
			if (b % 2 == 0) {
				b /= 2;
			} else {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	if (a != b) {
		cout << "NO" << endl;
		return 0;
	}
	ans.push_back(a);
	cout << "YES" << endl;
	reverse(ans.begin(), ans.end());
	cout << (int)ans.size() << endl;
	for (auto x: ans) {
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}