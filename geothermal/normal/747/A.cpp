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

	int n, root;
	cin >> n;
	root = (int) sqrt(n);
	for (int i = root; i > 0; i--) {
		if (n % i == 0) {
			cout << i << " " << n / i << "\n";
			break;
		}
	}

	return 0;
}