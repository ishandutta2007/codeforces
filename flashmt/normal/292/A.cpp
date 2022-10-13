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
	int n, c, t, maxSize = 0, queueSize = 0, cur = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> c;
		queueSize = max(0, queueSize - (t - cur));
		queueSize += c;
		maxSize = max(maxSize, queueSize);
		cur = t;
	}
	cout << cur + queueSize << ' ' << maxSize << endl;
}