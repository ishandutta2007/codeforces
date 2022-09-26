#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int x;

vector<pair<int,int> > ans;

int main()
{
	cin >> x;
	for (int i = 19;i >= 0;i--)
		if (~x >> i & 1)
		{
			ans.push_back(make_pair(1,i + 1));
			x ^= (1 << (i + 1)) - 1;
			if (x % (1 << (i + 1)) == (1 << (i + 1)) - 1)
				break;
			ans.push_back(make_pair(2,1));
			x++;
		}
	cout << ans.size() << endl;
	for (int i = 0;i < ans.size();i++)
		if (ans[i].first == 1)
			cout << ans[i].second << ' ';
	cout << endl;
	return 0;
}