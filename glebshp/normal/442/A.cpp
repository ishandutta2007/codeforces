#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 10;

int cnt[size][size];
int help[size][size];

bool isgood(int m1, int m2) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			for (int p = 0; p < 5; p++)
				for (int q = 0; q < 5; q++) {
					if (cnt[i][j] > 0 && cnt[p][q] > 0 && (i != p || j != q)) {
						bool flag = false;
						if (i != p && (((m1 >> i) & 1) + ((m1 >> p) & 1)) > 0)
							flag = true;
						if (j != q && (((m2 >> j) & 1) + ((m2 >> q) & 1)) > 0)
							flag = true;
						if (!flag)
							return false;
					}
				}	
		}

	return true;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    map <char, int> val;
    val['R'] = 0;
    val['G'] = 1;
    val['B'] = 2;
    val['Y'] = 3;
    val['W'] = 4;

    int n;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> str;
    	int x = val[str[0]];
    	int y = str[1] - '1';
    	cnt[x][y]++;
    }

    int ans = 10;
    for (int i = 0; i < 32; i++)
    	for (int j = 0; j < 32; j++) {
    	   	if (isgood(i, j))
    	   		ans = min(ans, __builtin_popcount(i) + __builtin_popcount(j));
    	}

    cout << ans << endl;

    return 0;
}