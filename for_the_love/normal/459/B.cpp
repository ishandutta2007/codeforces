#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
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

const DB eps = 1e-6;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


map <int, int> S;
int main(){
    int n, x, mn = INF, mx = -INF;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        mn = min(x, mn), mx = max(mx, x);
        S[x]++;
    }
    LL ans = (LL)S[mx] * S[mn];
    if (mn == mx) ans = (LL)S[mx] * (S[mn] - 1) / 2;
    cout << mx - mn << " " << ans << endl;
}