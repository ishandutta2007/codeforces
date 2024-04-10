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
#include <vector>
#include <bitset>


using namespace std;


int m;


int main() {
	cin >> m;
	int sum = 0;
	int sum1 = 0;
	vector<int> ans;
	for (int i = 1; i <= max(10, 12 * m); i++) {
		int i1 = i;
		while (i1 % 2 == 0) {
			i1 /= 2;
			sum++;
		}
		while (i1 % 5 == 0) {
			i1 /= 5;
			sum1++;
		}
		if (min(sum, sum1) == m) {
			ans.push_back(i);
		}
	}
	cout << (int)ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}