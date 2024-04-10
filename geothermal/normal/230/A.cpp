/*
 * Main.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: Jay Leeds
 */

/*#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>*/
#include <bits/stdc++.h>
using namespace std;

bool pairCompare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first != p2.first) return p1.first < p2.first;
	return p1.second > p2.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int s, n;
	vector<pair<int, int> > drags;
	cin >> s >> n;
	for (int i = 0; i < n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		drags.push_back(make_pair(n1, n2));

	}
	sort(drags.begin(), drags.end());
	bool defeated = false;
	for (int i = 0; i < n; i++) {
		pair<int, int> p = drags.at(i);
		if (s > p.first) {
			s = s + p.second;
		} else {
			defeated = true;
			break;
		}
	}
	if (defeated) {
		cout << "NO" << endl;
	} else cout << "YES" << endl;



	return 0;
}