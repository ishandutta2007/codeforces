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
	int n, count = 0;
	vector<int> a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m1, m2;
		cin >> m1 >> m2;
		a.push_back(m1);
		b.push_back(m2);
	}
	for (int i = 0; i < n; i++) {
		for (int i2 = 0; i2 < n; i2++) {
			if(a.at(i) == b.at(i2)) count++;
		}
	}

	cout << count;
	return 0;
}