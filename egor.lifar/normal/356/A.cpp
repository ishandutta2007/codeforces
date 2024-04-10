#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <tuple>
#include <unordered_set>


using namespace std;


int n, m;
int l[300000], r[300000], x[300000];
int nextt[300000];


void make_nextt(int v) {
	nextt[v] = v;
}


int find_nextt(int v) {
	if (nextt[v] >= n) {
		return n;
	}
	if (nextt[v] == v) {
		return v;
	}
	nextt[v] = find_nextt(nextt[v]);
	return nextt[v];
}


int ans[300000];


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &l[i], &r[i], &x[i]);
		l[i]--; r[i]--; x[i]--;
	}
	for (int i = 0; i < n; i++) {
		make_nextt(i);
	}
	for (int i = 0; i < m; i++) {
		int pos = find_nextt(l[i]);
		while (pos <= r[i]) {
			//cout << i + 1 << endl;
			if (pos == x[i]) {
				pos++;
			} else {
				ans[pos] = x[i] + 1;
				nextt[pos] = pos + 1;
			}
			if (pos > r[i]) {
				break;
			}
			//cout << nextt[pos] << ' ' << pos << endl;
			pos = find_nextt(pos);
			//cout << i + 1 << endl;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	cout << endl;
    return 0;
}