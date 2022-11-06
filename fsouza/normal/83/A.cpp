#include <iostream>
#include <cstdio>

typedef long long lint;

using namespace std;

int main()
{
	int n;

	cin >> n;

	lint ret = 0;

	int last = 1000000002;
	int many = 0;

	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		if (v != last) {
			last = v;
			many = 1;
		} else
			many ++;
		ret += (lint)many;
	}
	
	cout << ret << endl;

	return 0;
}