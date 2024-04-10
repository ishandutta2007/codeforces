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
	int n, m, max = -2, index = -1;
	cin >> n >> m;
	for (int i = 1; i < n+1; i++)
	{
		int curBase, cur;
		cin >> curBase;
		if (curBase % m == 0) curBase--;
		cur = curBase / m;
		if (cur >= max) {
			max = cur;
			index = i;
		}
	}

	cout << index;
	return 0;
}