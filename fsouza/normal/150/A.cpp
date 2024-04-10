#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

typedef long long lint;

using namespace std;

vector <pair <lint, int> > factorize(lint n)
{
	vector <pair <lint, int> > ret;

	for (lint x = 2; x*x <= n; x++) {
		if (n%x == 0) {
			int exp = 0;
			while (n%x == 0) {
				exp ++;
				n /= x;
			}
			ret.push_back(make_pair(x, exp));
		}
	}

	if (n != 1)
		ret.push_back(make_pair(n, 1));

	return ret;
}

int main()
{
	lint q;

	cin >> q;

	vector <pair <lint, int> > facts = factorize(q);

	int sumexp = 0;
	for (int i = 0; i < (int)facts.size(); i++)
		sumexp += facts[i].second;
	
	if (sumexp <= 1) {
		cout << 1 << endl << 0 << endl;
	} else if (sumexp == 2) {
		cout << 2 << endl;
	} else {
		cout << 1 << endl;
		lint res = 1;
		
		int remain = 2;
		for (int i = 0; i < (int)facts.size(); i++) {
			while (facts[i].second > 0 && remain > 0) {
				res *= facts[i].first;
				facts[i].second --;
				remain --;
			}
		}
		
		cout << res << endl;
	}

	return 0;
}