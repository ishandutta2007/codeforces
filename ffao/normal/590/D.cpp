#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n, k, s;

int dp[2][152][5630];
int a[152];

int main() {
    scanf("%d %d %d", &n, &k, &s);
    REP(i, n) scanf("%d", &a[i]);

    for (int pos = n; pos >= 0; pos--) {
        for (int ch = 0; ch <= k; ch++) {
            for (int made = 0; made <= min(5625, s); made++) {
                int &ref = dp[pos&1][ch][made];
                if (pos == n) {
                    if (ch == k) ref = 0;
                    else ref = 1000000000;
                    continue;
                }

                ref = 1000000000;
                
                int rem = n - pos;
                if (ch + rem < k) {
                    continue;
                }

                // don't choose
                if (ch + rem - 1 >= k) {
                    int renegaded = pos - ch;
                    int loc = k + renegaded;
                    if (made + (loc - pos) <= s) {
                        ref = dp[(pos&1)^1][ch][made + (loc - pos)];
                    }
                }

                if (ch < k) {
                    ref = min(ref, dp[(pos&1)^1][ch+1][made] + a[pos]);
                }
            }
        }
    }

    printf("%d\n", dp[0][0][0]);
}