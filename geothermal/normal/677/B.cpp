/*
 * Main.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: Jay Leeds
 */

#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, h;
	long long curh = 0, i = 0;
	double k;
	queue<int> q;
	cin >> n >> h >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}

	while (!q.empty()) {

		while (!q.empty() && curh + q.front() <= h) {
			curh = curh + q.front();
			q.pop();

		}
		if (!q.empty()) {
			double max = h - q.front();
			double reduce = curh - max;
			int num = ceil(reduce / k);
			i = i + num;
			curh = curh - num * k;
		} else {
			int num = ceil(curh / k);
			i = i + num;
			curh = curh - num * k;
		}
		if (curh < 0) curh = 0;
	}
	cout << i;

	return 0;
}