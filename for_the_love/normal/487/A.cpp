#pragma  comment(linker, "/STACK:36777216")
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lc(x) (x << 1)
#define  rc(x) (lc(x) + 1)
#define  lowbit(x) (x & (-x))
#define  PI    (acos(-1))
#define  lowbit(x) (x & (-x))
#define  LL    long long
#define  DB    double
#define  ULL   unsigned long long
#define  PII   pair<LL, int>
#define  PLL   pair<LL, LL>
#define  PB    push_back
#define  MP    make_pair

using namespace std;

const int N = 1e5 + 7;
const int INF = 0x3fffffff;
const int MOD = 18953423;
const DB  EPS = 1e-8;


int hpy, atky, defy, hpm, atkm, defm, h, a, d;
int main(){
    scanf("%d%d%d", &hpy, &atky, &defy);
    scanf("%d%d%d", &hpm, &atkm, &defm);
    scanf("%d%d%d", &h, &a, &d);
    int ans = INF;

    for (int A = max(atky, defm + 1); A <= max(max(atky, defm + 1), hpm + defm); A++)
    for (int B = defy; B <= max(atkm, defy); B++){
        int t = (A - atky) * a + (B - defy) * d;
        int H = ((hpm - 1) / (A - defm) + 1) * max(0, atkm - B);
        t += max(H - hpy + 1, 0) * h;
        ans = min(ans, t);
    }
    printf("%d\n", ans);


}