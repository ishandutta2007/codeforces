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
#include <sstream>
using namespace std;

int gcd(int x, int y)
{
	return x && y ? gcd(y, x % y) : x + y;
}

int main()
{
	int n, a[111];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int g = 0, mx = 0;
	for (int i = 0; i < n; i++) g = gcd(g, a[i]), mx = max(mx, a[i]);
	
	mx /= g;
	puts((mx - n) % 2 ? "Alice" : "Bob");
}