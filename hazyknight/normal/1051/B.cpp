#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector> 

using namespace std;

long long l,r;

int main()
{
	ios::sync_with_stdio(false);
	cin >> l >> r;
	cout << "YES" << endl;
	for (long long i = l;i <= r;i += 2)
		cout << i << ' ' << i + 1 << endl;
	return 0;
}