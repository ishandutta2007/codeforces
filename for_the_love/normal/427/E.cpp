#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;


int x[N], n, m;

LL Calc(int l){
    LL ret = 0;
    int po = lower_bound(x, x + n, l) - x;
    int mn = INF, cnt = 0;
    for (int i = 0; i < po; i++){
        if (!cnt) mn = x[i];
        cnt++;
        if (cnt == m){
            cnt = 0;
            ret += abs(l - mn);
        }
    }
    if (cnt){
        cnt = 0;
        ret += abs(l - mn);

    }
    int mx;
    for (int i = n - 1; i >= po; i--){
        if (!cnt) mx = x[i];
        cnt++;
        if (cnt == m){
            cnt = 0;
            ret += abs(l - mx);
        }
    }
    if (cnt){
        cnt = 0;
        ret += abs(l - mx);

    }
    return ret * 2;
}

int main(){
    scanf("%d%d", &n, &m);
    int l = INF, r = -INF;
    for (int i = 0; i < n; i++){
        scanf("%d", &x[i]);
        l = min(l, x[i]), r = max(r, x[i]);
    }
    while (l + 20 <= r){
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (Calc(m1) > Calc(m2)) l = m1; else r = m2;
    }
    LL ans = (LL)INF * INF;
    for (int i = l; i <= r; i++)
        ans = min(ans, Calc(i));
    cout << ans << endl;
}