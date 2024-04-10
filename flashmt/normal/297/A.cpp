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

int main()
{
	string a, b;
	cin >> a >> b;
	
	int x = 0, y = 0;
	for (int i = 0; i < int(a.size()); i++) x += a[i] - '0';
	for (int i = 0; i < int(b.size()); i++) y += b[i] - '0';
	
	if ((x + 1) / 2 < (y + 1) / 2) puts("NO");
	else puts("YES");
}