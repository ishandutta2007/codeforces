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

#define INF (INT_MAX/3)
#define MAXNPSUM 100

typedef long long lint;

using namespace std;

const int ndigit = 20;
const int maxcarry = 4;

int npsum;
int psums[MAXNPSUM];
int psumsvals[MAXNPSUM][6];

int target[ndigit];

bool dp[ndigit+1][maxcarry+1];

lint result[6][ndigit];

void solve()
{
	for (int c = 0; c <= maxcarry; c++)
		dp[ndigit][c] = false;
	dp[ndigit][0] = true;

	for (int d = ndigit-1; d >= 0; d--) {
		for (int c = 0; c <= maxcarry; c++) {
			dp[d][c] = false;

			for (int i = 0; i < npsum; i++) {
				int val = c + psums[i];

				int have = val%10;
				int newcarry = val/10;

				if (have == target[d] && dp[d+1][newcarry]) {
					dp[d][c] = true;
					break;
				}
			}
		}
	}
	
	if (dp[0][0] == false) {
		cout << "-1" << endl;
	} else {
		int c = 0;

		for (int d = 0; d < ndigit; d++) {

			for (int i = 0; i < npsum; i++) {
				int val = c + psums[i];

				int have = val%10;
				int newcarry = val/10;

				if (have == target[d] && dp[d+1][newcarry]) {
					for (int j = 0; j < 6; j++) {
						result[j][d] = psumsvals[i][j];
					}
					
					c = newcarry;
					break;
				}
			}
		}

		for (int j = 0; j < 6; j++) {
			if (j-1 >= 0) cout << " ";
			lint v = 0;
			for (int d = ndigit-1; d >= 0; d--) {
				v = 10LL*v + result[j][d];
			}
			cout << v;
		}
		cout << endl;
	}
}

int main(int argc, char ** argv)
{
	map <int, vector <int> > temp;

	for (int s = (1<<(2*6))-1; s >= 0; s--) {
		const int lucky[4] = {0, 4, 7, -1};
		vector <int> vals(6, 0);
		int sum = 0;
		for (int i = 0; i < 6; i++) {

			vals[i] = lucky[(s>>(2*i))&3];
			if (vals[i] == -1) goto next;
			sum += vals[i];
		}
		temp[sum] = vals;

	next:;
	}

	npsum = 0;
	map <int, vector <int> >::iterator it;
	for (it = temp.begin(); it != temp.end(); it++) {
		int sum = 0;
		vector <int> &bla = it -> second;
		for (int j = 0; j < (int)bla.size(); j++) {
			psumsvals[npsum][j] = bla[j];
			sum += bla[j];
		}
		psums[npsum++] = sum;
	}

	int ntest;

	cin >> ntest;
	
	for (int t = 0; t < ntest; t++) {
		lint n;

		cin >> n;

		for (int i = 0; i < ndigit; i++) {
			target[i] = n%10;
			n /= 10;
		}

		solve();
	}

	return 0;
}