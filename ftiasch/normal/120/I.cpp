#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <complex> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cassert> 
using namespace std;

const char MAGIC[][10] = {
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011"
};

int common[10][10];

const int maxn = 111111;
const int inf = 1000000000;

char digits[maxn + maxn];

//int memo[maxn][2][3];

int n;

inline int signum(int a)
{
    return a < 0 ? -1 : a > 0;
}
/*
int go(int pos, int gt, int sig)
{
    if (gt)
        sig = 0;
    int &ret = memo[pos][gt][sig + 1];
    if (ret != -1)
        return ret;
    if (pos == n) {
        if (!gt && sig <= 0)
            return ret = -inf;
        return ret = 0;
    }
    ret = -inf;
    for (int d1 = 0; d1 < 10; d1++) {
        if (gt || d1 >= digits[pos] - '0') {
            for (int d2 = 0; d2 < 10; d2++) {
                ret = max(ret, go( pos + 1
                                 , gt || d1 > digits[pos] - '0'
                                 , sig == 0 ? signum(d2 - (digits[pos + n] - '0')) : sig
                                 ) + common[d1][d2]);

            }
        }
    }
    return ret;
}*/

int memo1[maxn][2][3];

int lastSig;

int go1(int pos, int gt, int sig)
{
    if (gt)
        sig = 0;
    int &ret = memo1[pos][gt][sig + 1];
    if (ret != -1)
        return ret;
    if (pos == n) {
        if (!gt && sig <= 0)
            return ret = -inf;
        if (sig != lastSig)
            return ret = -inf;
        return ret = 0;
    }
    ret = -inf;
    for (int d1 = 0; d1 < 10; d1++) {
        if (gt || d1 >= digits[pos] - '0') {
            for (int d2 = 0; d2 < 10; d2++) {
                ret = max(ret, go1( pos + 1
                                  , gt || d1 > digits[pos] - '0'
                                  , sig == 0 ? signum(d2 - (digits[pos + n] - '0')) : sig
                                  ) + common[d1][d2]);

            }
        }
    }
    return ret;
}


char ans[maxn + maxn];
char ans2[maxn + maxn];

bool constructFst(int pos, int gt, int sig, int target)
{
    if (pos == n)
        return true;
    for (int d1 = 0; d1 < 10; d1++) {
        if (gt || d1 >= digits[pos] - '0') {
            int minv = inf;
            int mind2 = 0;
            for (int d2 = 0; d2 < 10; d2++) {
                int res = go1( pos + 1
                             , gt || d1 > digits[pos] - '0'
                             , sig == 0 ? signum(d2 - (digits[pos + n] - '0')) : sig
                             );
                if (res + common[d1][d2] > target) {
                    if (minv >= target - common[d1][d2]) {
                        minv = target - common[d1][d2];
                        mind2 = d2;
                    }
                }
            }
            if (minv < inf) {
                ans[pos] = '0' + d1;
                return constructFst( pos + 1
                                   , gt || d1 > digits[pos] - '0'
                                   , sig == 0 ? signum(mind2 - (digits[pos + n] - '0')) : sig
                                   , minv
                                   );
            }
        }
    }
    return false;
}

int memo2[maxn][2][3];

int go2(int pos, int gt, int sig)
{
    if (gt)
        sig = 0;
    int &ret = memo2[pos][gt][sig + 1];
    if (ret != -1)
        return ret;
    if (pos == n) {
        if (!gt && sig <= 0)
            return ret = -inf;
        return ret = 0;
    }
    ret = -inf;
    for (int d1 = 0; d1 < 10; d1++) {
        if (gt || d1 >= digits[pos] - '0') {
            if (d1 != ans[pos] - '0')
                continue;
            for (int d2 = 0; d2 < 10; d2++) {
                ret = max(ret, go2( pos + 1
                                  , gt || d1 > digits[pos] - '0'
                                  , sig == 0 ? signum(d2 - (digits[pos + n] - '0')) : sig
                                  ) + common[d1][d2]);

            }
        }
    }
    return ret;
}

void constructSnd(int pos, int gt, int sig, int target)
{
    if (pos == n)
        return;
    for (int d1 = 0; d1 < 10; d1++) {
        if (gt || d1 >= digits[pos] - '0') {
            if (d1 != ans[pos] - '0')
                continue;
            for (int d2 = 0; d2 < 10; d2++) {
                int res = go2( pos + 1
                             , gt || d1 > digits[pos] - '0'
                             , sig == 0 ? signum(d2 - (digits[pos + n] - '0')) : sig
                             );
                if (res + common[d1][d2] > target) {
                    ans[pos + n] = '0' + d2;
                    constructSnd( pos + 1
                                , gt || d1 > digits[pos] - '0'
                                , sig == 0 ? signum(d2 - (digits[pos + n] - '0')) : sig
                                , target - common[d1][d2]
                                );
                    return;
                }
            }
        }
    }
    puts("ERROR");
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 7; k++)
                if (MAGIC[i][k] == '1' && MAGIC[j][k] == '1')
                    common[i][j] ++;
    scanf("%s", digits);
    n = strlen(digits) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += common[digits[i] - '0'][digits[i + n] - '0'];
    }
    /*memset(memo, -1, sizeof(memo));
    if (go(0, 0, 0) <= sum)
        puts("-1");
    else {*/
        ans2[0] = 'Z';
        for (lastSig = -1; lastSig <= 1; lastSig++) {
            memset(memo1, -1, sizeof(memo1));
            if (constructFst(0, 0, 0, sum)) {
                if (strcmp(ans, ans2) < 0) {
                    strcpy(ans2, ans);
                }
            }
        }
        if (ans2[0] == 'Z') {
            puts("-1");
            return 0;
        }
        strcpy(ans, ans2);
        memset(memo2, -1, sizeof(memo2));
        constructSnd(0, 0, 0, sum);
        ans[n + n] = 0;
        puts(ans);
    //}
}