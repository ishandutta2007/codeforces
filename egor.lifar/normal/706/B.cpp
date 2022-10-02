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


int n;
vector<int> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int m;
		scanf("%d", &m);
		printf("%d\n", (int)(upper_bound(v.begin(), v.end(), m) - v.begin()));
	}
    return 0;
}