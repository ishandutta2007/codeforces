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

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

int main(int argc, char ** argv)
{
	int n;
	cin >> n;

	vector <int> mids;
	lint topsum = 0, botsum = 0;
	
	for (int i = 0; i < n; i++) {
		int many;
		cin >> many;
		for (int j = 0; j < many/2; j++) {
			int v;
			cin >> v;
			topsum += v;
		}
		if (many%2) {
			int v;
			cin >> v;
			mids.push_back(v);
		}
		for (int j = 0; j < many/2; j++) {
			int v;
			cin >> v;
			botsum += v;
		}		
	}

	sort(mids.rbegin(), mids.rend());

	for (int i = 0; i < (int)mids.size(); i++)
		if (i%2) {
			botsum += mids[i];
		} else {
			topsum += mids[i];
		}

	cout << topsum << " " << botsum << endl;

	return 0;
}