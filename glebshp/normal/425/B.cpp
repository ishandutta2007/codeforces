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
const int size = 200;
const int ssize = 11;

int n, m, k;
int field[size][size];
int help[size][size];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++)
    		scanf("%d", &field[i][j]);
    if (n > m) {
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < m; j++)
    			help[j][i] = field[i][j];
    	swap(n, m);
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < m; j++)
    			field[i][j] = help[i][j];
    }

    if (n > k) {
    	int ans = -1;
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < m; j++) {
    			int cur = 0;
    			for (int p = 0; p < n; p++)
    				for (int q = 0; q < m; q++) {
    					cur += (field[i][j] ^ field[i][q] ^ field[p][j] ^ field[p][q]);
    				}
    		   	if (cur <= k && (ans == -1 || ans > cur)) {
    		   		ans = cur;
    		   	}
    		}
    	cout << ans << endl;
    	return 0;
    }
	
	int ans = -1;
    for (int i = 0; i < (1 << n); i++) {
    	int cur = 0;
    	for (int j = 0; j < m; j++) {
    		int bad = 0;
    		for (int k = 0; k < n; k++)
    			bad += (field[k][j] ^ ((i >> k) & 1));
    		bad = min(bad, n - bad);
    		cur += bad;
    	}
    	if (cur <= k && (ans == -1 || ans > cur)) {
    		ans = cur;
    	}
    }
    cout << ans << endl;

    return 0;
}