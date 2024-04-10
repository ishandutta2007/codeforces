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


int n;
int a[100001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int l = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= l + 1) {
			l++;
		}
	}
	cout << l + 1 << endl;
    return 0;
}