#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>
#include <stack>
#include <cmath> 

using namespace std;

int n,k,t;

int main()
{
	cin >> n >> k >> t;
	if (t < k)
		cout << t << endl;
	else if (t < n + 1)
		cout << k << endl;
	else
		cout << n + k - t << endl;
	return 0;
}