/*
 * Main.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: Jay Leeds
 */

#include<iostream>
using namespace std;

int main()
{
	int n, min, max, count = 0;

	cin >> n >> min;

	max = min;
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		if (x < min) {
			count++;
			min = x;
		} else if (x > max) {
			count++;
			max = x;
		}
	}
	cout << count;
	return 0;
}