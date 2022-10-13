#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n - k - 1; i++) cout << i << ' ';
	for (int i = 0; i <= k; i++) cout << n - i << ' ';
	puts("");		
}