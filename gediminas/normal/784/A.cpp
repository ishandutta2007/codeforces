#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
	/*
	1 => 4
	2 => 22
	3 => 27
	4 => 58
	5 => ?

	*/

	int i[] = {0,4, 22, 27, 58, 85, 94, 121, 166, 202, 265, 274, 319, 346, 355, 378, 382, 391, 438, 454, 483, 517,526, 535, 562, 576, 588, 627, 634, 636, 645, 648, 654, 663, 666, 690, 706, 728, 729, 762, 778, 825, 852, 861, 895, 913, 915, 922, 958, 985};

	long long n;
	cin >> n;

		cout <<  i[n] ;

	return 0;
}