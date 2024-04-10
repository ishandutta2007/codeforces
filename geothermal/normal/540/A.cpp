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
	string a, b;
	cin >> n >> a >> b;

	for (int i = 0; i < n; i++) {
		char ca, cb;
		int ia, ib;
		ca = a.at(0);
		cb = b.at(0);
		ia = ca - '0';
		ib = cb - '0';
		a = a.substr(1, a.size() - 1);
		b = b.substr(1, b.size() - 1);
		int num = abs(ia % 10 - ib % 10);
		count = count + min(num, 10 - num);
	}
	cout << count;

	return 0;
}