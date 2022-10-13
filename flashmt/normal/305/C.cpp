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
	int n, x;
	map <int,int> m;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x, m[x]++;
	
	int last, cnt = 0;
	for (map <int,int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cnt += it -> second % 2;
		last = it -> first;
		if (it -> second >= 2) m[it -> first + 1] += it -> second / 2;
	}
	
	cout << last + 1 - cnt << endl;
}