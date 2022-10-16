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

pair<int, int> a[1100000];
int f[1100000];
vector< vector<int> > sum;
vector< vector<int> > dp;

const int mod = 1000000007;
const int m = mod;

int n, k;
long long l;

long long r[1100000];

int main() {
    scanf("%d %lld %d", &n, &l, &k);
    
    r[1] = 1; 
    for (int i=2; i<1100000; ++i) r[i] = (m - (m/i) * r[m%i] % m) % m;

    dp = vector<vector<int>>(k+2, vector<int>(n+2, 0));
    sum = vector<vector<int>>(k+2, vector<int>(n+2, 0));

    REP(i, n) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    sort(a, a+n);

    for (int i = n-1; i >= 0; i--){ 
        f[i] = i;
        if (i != n-1 && a[i].first == a[i+1].first) f[i] = f[i+1];
    }

    int ans = 0;
    long long full_runs = l / n;
    long long add_run = l % n;

    long long comb_full_i = 1;
    long long comb_full_i1 = 1;

    REP(i, k+1) {
        REP(j, n) {
            if (i == 0) {
                if (j == 0) dp[i][j] = 1;
                else dp[i][j] = 0;
                continue;
            }

            dp[i][j] = sum[i-1][f[j]];
            //printf("%d %d -> %d\n", i, j, dp[i][j]);
            
            if (i <= full_runs) {
                long long choices = (full_runs-i+1) % mod;
                ans = (ans + choices * dp[i][j]) % mod;
            }

            if (i <= full_runs + 1 && a[j].second < add_run) {
                long long choices = 1;
                ans = (ans + choices * dp[i][j]) % mod;
            }
        }

        REP(j, n) {
            if (j == 0) sum[i][j] = dp[i][j];
            else sum[i][j] = (sum[i][j-1] + dp[i][j]) % mod;
        }

        comb_full_i1 = comb_full_i;
        comb_full_i = (comb_full_i * ((full_runs-i)%mod) ) % mod;
        comb_full_i = (comb_full_i * r[i+1]) % mod;
    }

    printf("%d\n", ans);
}