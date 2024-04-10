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

vector <pair <int, int> > result;

void move(pair <int, int> &from, pair <int, int> &to)
{
	from.first -= to.first;
	to.first *= 2;

	result.push_back(make_pair(to.second, from.second));
}

void removeone(pair <int, int> list[3])
{
	sort(list, list+3);

	if (list[0].first == 0) {
		swap(list[0], list[2]);
		return;
	}

	int q = list[1].first / list[0].first;

	for (int x = 1; q; x <<= 1)
		if (q & x) {
			move(list[1], list[0]);
			q -= x;
		} else
			move(list[2], list[0]);

	removeone(list);
}

int main(int argc, char ** argv)
{
	int n;
	vector <pair <int, int> > nums;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		if (v)
			nums.push_back(make_pair(v, i));
	}

	if (nums.size() < 2) {
		printf("-1\n");
		return 0;
	}

	result.clear();
	while (nums.size() > 2) {
		removeone(&nums[nums.size()-3]);
		nums.pop_back();
	}

	printf("%d\n", (int)result.size());
	for (int i = 0; i < (int)result.size(); i++)
		printf("%d %d\n", result[i].first+1, result[i].second+1);

	return 0;
}