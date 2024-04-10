#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int kMaxAns = 5 * 1000;
const int size = 1000;
const int scores[6] = {500, 1000, 1500, 2000, 2500, 3000};

int p[5], q[5];
int res[size][5];
int n;

int getscore(int cur, int s1, int s2, int s3, int s4, int s5) {
	int sum = 0;
	
	int costs[] = {s1, s2, s3, s4, s5};

	for (int i = 0; i < 5; i++) {
		if (res[cur][i] >= 0) {
			sum += scores[costs[i]] - scores[costs[i]] / 250 * res[cur][i];
		}
	}

	return sum;
}

int getminpos(int t, int q) {
	if (t == 0)
		return q / 2 + 1;
	if (t == 1)
		return q / 4 + 1;
	if (t == 2)
		return q / 8 + 1;
	if (t == 3)
		return q / 16 + 1;
	if (t == 4)
		return q / 32 + 1;
	if (t == 5)
		return 0;
}

int getmaxpos(int t, int q) {
	if (t == 0)
		return q;
	if (t == 1)
		return q / 2;
	if (t == 2)
		return q / 4;
	if (t == 3)
		return q / 8;
	if (t == 4)
		return q / 16;
	if (t == 5)
		return q / 32;
}

bool check(int tot, int s1, int s2, int s3, int s4, int s5) {
	int vas = getscore(0, s1, s2, s3, s4, s5);
	int pet = getscore(1, s1, s2, s3, s4, s5);
	
	if (vas <= pet)
		return false;

	bool flag = true;
	int costs[] = {s1, s2, s3, s4, s5};

	for (int i = 0; i < 5; i++) {
		int lbn = getminpos(costs[i], tot);	
		int rbn = getmaxpos(costs[i], tot);

		int lbcan = p[i];
		int rbcan = p[i];
		if (res[0][i] >= 0)
			rbcan += (tot - n);

		if (lbn > rbcan || rbn < lbcan || lbn > rbn) {
			flag = false;
		}
	}

	return flag;
}

int main () {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < 5; j++)
    		cin >> res[i][j];

    for (int i = 0; i < 5; i++) {
    	p[i] = 0;
    	q[i] = n;
    	for (int j = 0; j < n; j++)
    		p[i] += (res[j][i] >= 0);
    }

    for (int ans = 0; ans < kMaxAns; ans++) {
    	for (int s1 = 0; s1 < 6; s1++) {
    		for (int s2 = 0; s2 < 6; s2++) {
    			for (int s3 = 0; s3 < 6; s3++) {
    				for (int s4 = 0; s4 < 6; s4++) {
    					for (int s5 = 0; s5 < 6; s5++) {
    						if (check(n + ans, s1, s2, s3, s4, s5)) {
    							cout << ans << endl;

    							return 0;
    						}
    					}
    				}
    			}
    		}
    	}
    }

    cout << -1 << endl;

//    cerr << (clock() + 0.0) / CLOCKS_PER_SEC << endl;

    return 0;
}