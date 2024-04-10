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

	ifstream input;
	input.open("input.txt");
	ofstream output;
	output.open("output.txt");
	string a, b;
	input >> a >> b;

	if ((a == "front" && b == "1") || (a == "back" && b == "2")) {
		output << "L";
	} else output << "R";

	return 0;
}