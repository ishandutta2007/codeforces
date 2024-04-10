#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-6;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

LL n, k, d1, d2;
bool check(LL a, LL b, LL c){
    LL p = min(a, min(b, c));
    if (p < 0){
        a -= p;
        b -= p;
        c -= p;
    }
    if (a + b + c > k) return 0;
    if ((k - a - b - c) % 3 != 0) return 0;
    LL t = max(a, max(b, c));
    LL x = t - a + t - b + t - c;
    x = n - x;
    if (x < 0) return 0;
    if (x % 3 != 0) return 0;
    return 1;
}
int main(){
    int cas;
    scanf("%d", &cas);
    while (cas--){
        cin >> n >> k >> d1 >> d2;
        n -= k;
        if (check(d1 + d2, d2, 0) || check(d2 - d1, d2, 0) || check(d1 - d2, -d2, 0) || check(-d1 - d2, -d2, 0)) puts("yes"); else puts("no");
    }
}