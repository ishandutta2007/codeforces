/*
 * test.cpp
 *
 *  Created on: Dec 21, 2016
 *      Author: Jay Leeds
 */

#include <iostream>;
#include <stdio.h>;

using namespace std;

int main()
{
	int a;
	cin >> a;
	if (a % 2 == 0 && a != 2) {
		cout << "YES" << endl;
	} else cout << "NO" << endl;
}