#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

#ifdef ONLINE_JUDGE
const int maxn=111111;
#else
const int maxn=100;
#endif

int a1, a2, a3, b1, b2, b3, n, c1, c2;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
	c1=(a1+a2+a3)/5;
	if ((a1+a2+a3)%5) c1++;
	c2=(b1+b2+b3)/10;
	if ((b1+b2+b3)%10) c2++;
	if (c1+c2 <= n) cout << "YES";
	else cout << "NO";
    return 0;
}