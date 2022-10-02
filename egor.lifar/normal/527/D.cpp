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


using namespace std;


struct node{
	int x, s;
};


bool operator <(const node a, const node b) {
	return a.x + a.s < b.x + b.s;
}


int n;
node a[200001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].s;
	}
	sort(a, a + n);
	int last = 0;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (a[i].x - a[i].s >= a[last].x + a[last].s) {
			last = i;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}