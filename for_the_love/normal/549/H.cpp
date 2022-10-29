#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int main(){
    DB a, b, c, d;
    double A, B, C, D;
    cin >> A >> B >> C >> D;
    a = A, b = B, c = C, d = D;

    DB l = 0, r = 2e9, ans;
    for (int i = 0; i < 100000; i++){
        DB mid = (l + r) / 2, mn1 = 1e18, mn2 = 1e18, mx1 = -1e18, mx2 = -1e18;
        mn1 = min(mn1, (a + mid) * (d + mid));
        mn1 = min(mn1, (a + mid) * (d - mid));
        mn1 = min(mn1, (a - mid) * (d + mid));
        mn1 = min(mn1, (a - mid) * (d - mid));

        mx1 = max(mx1, (a + mid) * (d + mid));
        mx1 = max(mx1, (a + mid) * (d - mid));
        mx1 = max(mx1, (a - mid) * (d + mid));
        mx1 = max(mx1, (a - mid) * (d - mid));

        mn2 = min(mn2, (b + mid) * (c + mid));
        mn2 = min(mn2, (b + mid) * (c - mid));
        mn2 = min(mn2, (b - mid) * (c + mid));
        mn2 = min(mn2, (b - mid) * (c - mid));

        mx2 = max(mx2, (b + mid) * (c + mid));
        mx2 = max(mx2, (b + mid) * (c - mid));
        mx2 = max(mx2, (b - mid) * (c + mid));
        mx2 = max(mx2, (b - mid) * (c - mid));

        if ((mn1 >= mn2 && mn1 <= mx2) || (mx1 >= mn2 && mx1 <= mx2) || (mx1 >= mx2 && mn1 <= mn2)){
            r = mid;
            ans = mid;
        }else l = mid;
    }
    printf("%.10f\n", ((double)ans));
}