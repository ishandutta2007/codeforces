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
 

using namespace std;


int n;
int a[100000];
int b[100000];


int main() {
	cin >> n;
	int k1;
	cin >> k1;
	queue<int> q, q1;
	for (int i = 0; i < k1; i++) {
		int a;
		cin >> a;
		q.push(a);
	}
	int k2;
	cin >> k2;
	for (int i = 0; i < k2; i++) {
		int b;
		cin >> b;
		q1.push(b);
	}
	int t = 0;
	while (!q.empty() && !q1.empty() && t < 2000000) {
		t++;
		int a = q.front();
		int b = q1.front();
		q.pop();
		q1.pop();
		if (b > a) {
			q1.push(a);
			q1.push(b);
		} else {
			q.push(b);
			q.push(a);
		}
	}
	if (q.empty()) {
		cout << t << ' ' << 2 << endl;
		return 0;
	}
	if (q1.empty()) {
		cout << t << ' ' << 1 << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}