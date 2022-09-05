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
	vector<vector<int> > pairings;
	vector<int> v0, v1, v2, v3, v4, v5, v6, v7, v8;
	v0 = {0, 1, 3};
	v1 = {0, 1, 2, 4};
	v2 = {1, 2, 5};
	v3 = {0, 3, 6, 4};
	v4 = {1, 3, 4, 5, 7};
	v5 = {2, 4, 5, 8};
	v6 = {3, 6, 7};
	v7 = {4, 6, 7, 8};
	v8 = {5, 7, 8};
	pairings.push_back(v0);
	pairings.push_back(v1);
	pairings.push_back(v2);
	pairings.push_back(v3);
	pairings.push_back(v4);
	pairings.push_back(v5);
	pairings.push_back(v6);
	pairings.push_back(v7);
	pairings.push_back(v8);

	bool final [9];
	bool conversion [9];
	for (int i = 0; i < 9; i++) {
		int n;
		cin >> n;
		conversion[i] = n % 2;
		final[i] = true;
	}

	for (int i = 0; i < 9; i++) {
		if (conversion[i]) {
			for (int i2 : pairings.at(i)) {
				final[i2] = !final[i2];
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		cout << (int) final[i];
		if (i % 3 == 2) cout << "\n";
	}
	return 0;
}