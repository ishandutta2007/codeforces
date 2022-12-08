#include <iostream>
#include <cstdio>

#include <utility>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N;

struct z
{
	pair<int, int> v;
	int i;
	bool operator < (const z& o) const {return v < o.v;}
	bool operator > (const z& o) const {return v > o.v;}
};
vector<z> x, y;
int main(void)
{
	scanf("%d", &N);
	for(int i = 1, a, b;i <= N;i++)
	{
		scanf("%d%d", &a, &b);
		if(a < b) x.push_back({{a, b}, i});
		else y.push_back({{a, b}, i});
	}
	if(x.size() < y.size())
	{
		sort(y.begin(), y.end(), less<z>());
		printf("%lu\n", y.size());
		for(auto k : y) printf("%d\n", k.i);
	}
	else
	{
		sort(x.begin(), x.end(), greater<z>());
		printf("%lu\n", x.size());
		for(auto k : x) printf("%d\n", k.i);
	}
	return 0;
}