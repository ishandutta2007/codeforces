#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int n;

vector<pair<int,int> > ans;

bool isprime(int v)
{
	for (int i = 2;i * i <= v;i++)
		if (v % i == 0)
			return 0;
	return 1;
}

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		ans.push_back(make_pair(i,i % n + 1));
	int e = n,id = 1;
	while (!isprime(e))
	{
		e++;
		ans.push_back(make_pair(id,n - id));
		id++;
	}
	printf("%d\n",(int)ans.size());
	for (int i = 0;i < ans.size();i++)
		cout << ans[i].first << ' ' << ans[i].second << endl;
	return 0;
}