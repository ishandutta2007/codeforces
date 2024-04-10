#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

typedef long long int64;
typedef unsigned long long qword;
typedef unsigned int uint;

const int INFI_INT = 1<<30;
const int64 INFI_INT64 = (int64)(1<<30) * (int64)(1<<30);
const double PI = 3.14159265358979323846264338;

template <class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a%b); }
template <class T> T absval(T x) { return x > 0 ? x : -x; }

#define forint(i, s, t) for (int i = (int)(s); i <= (int)(t); ++ i)
#define forintdown(i, s, t) for (int i = (int)(s); i >= (int)(t); -- i)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define movechar(a, b) memmove(b, a, sizeof(a))

char digits[10010];
int n, k;

void solve() {
    scanf("%d%d%s", &n, &k, digits);
    string answer = "";
    int best = INFI_INT;
    forint (dd, 0, 9) {
        string cur = string(digits);
        int rest = k;
        int cost = 0;
        forint (delta, 0, 9) {
            forint (i, 0, cur.size()-1)
                if (rest > 0 && (int)(cur[i] - '0') == dd + delta) {
                    cur[i] = (char)('0' + dd);
                    -- rest;
                    cost += delta;
                }
            if (delta == 0)
                continue;
            forintdown (i, cur.size()-1, 0)
                if (rest > 0 && (int)(cur[i] - '0') == dd - delta) {
                    cur[i] = (char)('0' + dd);
                    -- rest;
                    cost += delta;
                }
        }
        //printf("rest=%d cost=%d cur=%s\n", rest, cost, cur.c_str());
        if (cost < best || (cost == best && cur < answer))
            best = cost, answer = cur;
    }
    printf("%d\n%s\n", best, answer.c_str());
}

int main() {
    /*
    freopen("5.in", "r", stdin);
    freopen("5.out", "w", stdout);
    //*/
    /*
  	for (;;)
    //*/
    solve();
    return 0;
}