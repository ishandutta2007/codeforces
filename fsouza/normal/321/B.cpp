#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

typedef long long lint;

using namespace std;

int case1(vector <int> a1, vector <int> d1, vector <int> a2)
{
	int ret = 0;

	reverse(d1.begin(), d1.end());

	vector <int> newa2;

	int i;
	for (i = 0; i < a2.size(); i++)
		if (!d1.empty() && a2[i] > d1.back())
			d1.pop_back();
		else
			newa2.push_back(a2[i]);
	a2 = newa2;

	if (!d1.empty()) return 0;

	for (i = a2.size()-1; i >= 0 && !a1.empty(); i--) {
		if (a2[i] < a1.back())
			return 0;
		ret += a2[i] - a1.back();
		a1.pop_back();
		a2.pop_back();
	}

	if (!a1.empty()) return 0;
	
	for (i = 0; i < a2.size(); i++)
		ret += a2[i];

	return ret;
}


int case2(vector <int> a1, vector <int> d1, vector <int> a2)
{
	int ret = 0;
	int i = 0, j = a2.size()-1;

	while (i < a1.size() && j >= 0 && a2[j] > a1[i]) {
		ret += a2[j] - a1[i];
		i++, j--;
	}
	
	return ret;
}

int main(int argc, char ** argv)
{
	int n, m;
	vector <int> a1, d1, a2;
	
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		char pos[16];
		int st;
		scanf(" %s %d", pos, &st);
		if (pos[0] == 'A')
			a1.push_back(st);
		else
			d1.push_back(st);
	}

	for (int i = 0; i < m; i++) {
		int st;
		scanf("%d", &st);
		a2.push_back(st);
	}

	sort(a1.begin(), a1.end());
	sort(d1.begin(), d1.end());
	sort(a2.begin(), a2.end());

	printf("%d\n", max(case1(a1,d1,a2), case2(a1,d1,a2)));

	return 0;
}