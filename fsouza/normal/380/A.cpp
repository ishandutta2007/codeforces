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

const int maxl = 100010;

int main(int argc, char ** argv)
{
	int m;
	vector <int> prefix;
	vector <pair <lint, lint> > ops;
	vector <lint> sizeacc;

	cin >> m;

	for (int i = 0; i < m; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			int num;
			cin >> num;
			if ((int)prefix.size() < maxl)
				prefix.push_back(num);

			ops.push_back(make_pair(-1, num));
			sizeacc.push_back(1);
		} else {
			lint l, c;
			cin >> l >> c;

			for (int k = 0; k < c && (int)prefix.size() < maxl; k++)
				for (int j = 0; j < l && (int)prefix.size() < maxl; j++)
					prefix.push_back(prefix[j]);

			ops.push_back(make_pair(l, c));
			sizeacc.push_back(l * c);
		}
	}

	for (int i = 1; i < (int)sizeacc.size(); i++) sizeacc[i] += sizeacc[i-1];
	sizeacc.insert(sizeacc.begin(), 0);

	vector <lint> result;

	int nq;

	cin >> nq;

	for (int q = 0; q < nq; q++) {
		lint id;
		cin >> id; id --;

		int pos = upper_bound(sizeacc.begin(), sizeacc.end(), id) - sizeacc.begin() - 1;
		id -= sizeacc[pos];

		if (ops[pos].first == -1) {
			result.push_back(ops[pos].second);
		} else {
			id %= ops[pos].first;
			result.push_back(prefix[id]);
		}
	}

	cout << result[0];

	for (int i = 1; i < (int)result.size(); i++) {
		cout << " " << result[i];
	}
	cout << endl;

	return 0;
}