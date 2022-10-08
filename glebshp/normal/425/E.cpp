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
const int size = 550;
const int mdl = 1000 * 1000 * 1000 + 7;

long long ans[2][size][size];
int n, h;
long long sum[size][size];
long long pw[size];

int main() {
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);



    cin >> n >> h;

    pw[0] = 1;
    for (int i = 1; i <= n + 1; i++)
    	pw[i] = (pw[i - 1] + pw[i - 1]) % mdl;

    ans[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j <= i; j++)
    		for (int k = 0; k <= i; k++) {
    			ans[i & 1][j][k] = ans[1 ^ (i & 1)][j][k];
    			if (j > 0)
    				ans[i & 1][j][k] = (ans[i & 1][j][k] * pw[k]) % mdl;
    		}
    	for (int j = 0; j <= i; j++) {
    	   	sum[j][0] = ans[1 ^ (i & 1)][j][0];
    		for (int k = 1; k <= i; k++) {
    			sum[j][k] = (sum[j][k - 1] + ans[1 ^ (i & 1)][j][k]) % mdl;
    		}
    	}
    	for (int j = 1; j <= i; j++)
    		for (int k = 1; k <= i; k++) {
	   			ans[i & 1][j][i] = (ans[i & 1][j][i] + sum[j - 1][k - 1] * pw[k - 1]) % mdl;
//    			ans[i & 1][j][k] = (ans[i & 1][j][k] + sum[j - 1][k - 1] * pw[k - 1]) % mdl;
//    			cerr << i << ' ' << j << ' ' << k << ' ' << ans[i & 1][j][k] << endl;
    		}
    }

    long long tans = 0;
    for (int i = 0; i <= n; i++)
    	tans = (tans + ans[n & 1][h][i]) % mdl;
    cout << tans << endl;

    return 0;
}