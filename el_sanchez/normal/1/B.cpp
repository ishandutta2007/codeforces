#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <complex>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define sqr(x) (x)*(x)
#define odd(x) (x % 2 == 1)
#define next(i,n) ((i == n) ? 1 : i + 1)   //1..n
#define prev(i,n) ((i == 1) ? n : i - 1)   //1..n

typedef long long int64;

const int MAXN = (int)1E5;
const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

int main() {

    long k, n;
    char w[MAXN+10];
    scanf("%d", &n);
    forn(i, n) {
        scanf("%s", &w);
        string str = w;
        long ch = 0, a = 0, b = 0, len = str.size();
        string ts;
        forn(j, len)
            if (('A' <= str[j]) && (str[j] <= 'Z'))
                ch++;
        if ((ch == 2) && (str[0] == 'R') && ('0' <= str[1]) && (str[1] <= '9')) {
            long j = 1;
            while (str[j] != 'C') {
                b = b * 10 + str[j] - '0';
                j++;
            }
            j++;
            while (j < len) {
                a = a * 10 + str[j] - '0';
                j++;
            }
            int m;
            while (a > 0) {
                m = a % 26;
                a /= 26;
                if (m == 0) {
                    m = 26;
                    a--;
                }
                ts = char('A' + m - 1) + ts;
            }

            printf("%s%d\n", ts.c_str(), b);
        } else {
            long l = 0;
            while (('A' <= str[l]) and (str[l] <= 'Z'))
                l++;
            long base = 1;
            ford(j, l) {
                b += (str[j] - 'A' + 1) * base;
                base *= 26;
            }
            long j = l;
            while (j < len) {
                a = a * 10 + str[j] - '0';
                j++;
            }
            printf("R%dC%d\n", a, b);
        }
    }

    return 0;
}