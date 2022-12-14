#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

const int mo = 1000000007;

LL f[1100][2];
int n;
int p[1100];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]);
    f[1][1] = 0;
    f[1][0] = 1;
    for (int i = 2; i <= n; ++i){
        f[i][1] = (f[i - 1][0] + 1) % mo;
        if (p[i] == i) f[i][0] = (f[i][1] + 1) % mo; else f[i][0] = (1 + 2ll * f[i][1] - f[p[i]][1] + mo) % mo;
    }
    LL ans = (f[n][0] + 1) % mo;
    cout << ans << '\n';
    return 0;
}