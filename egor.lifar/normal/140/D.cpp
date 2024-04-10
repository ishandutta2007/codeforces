#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;


int n;
int a[1000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int sum = 0;
	int k = 0;
	int g = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum > 710) {
			break;
		}
		k++;
		if (sum > 350) {
			g+= sum - 350;
		}
	}
	cout << k << ' ' << g << endl;
    return 0;
}