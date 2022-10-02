#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;


int n;
int ans = 0;
set<int> s;


void get(int i, int k) {
	if (i == 10) {
		if (n >= k) {
			s.insert(k);
		}
		return;
	}
	get(i + 1, k * 10 + 0);
	get(i + 1, k * 10 + 1);
}


int main() {
	cin >> n;
	get(0, 0);
	cout << s.size() - 1 << endl;
    return 0;
}