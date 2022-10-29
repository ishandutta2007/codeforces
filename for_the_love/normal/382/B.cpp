#include <map>
#include <set>
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
const int N = 2005;
long long a, b, w, x, c, st, len, cnt, g[N], v[N];

int main(){
    cin >> a >> b >> w >> x >> c;
    long long tb = b;
    long long now = 0, t = 0;
    while (1){
        if (v[b]){
            st = v[b] - 1;
            len = now - v[b];
            cnt = t - g[b];
            break;
        }
        v[b] = now;
        g[b] = t;
        t++;
        now += b / x + 1;
        b = w - (x - b % x);
    }
    b = tb;
    if (c <= a){
        puts("0");
        return 0;
    }
    for (int i = 1; i <= st; i++){
        if (b >= x) b -= x; else a--, b = w - (x - b);
        c--;
        if (c <= a){printf("%d\n", i);return 0;}
    }
    t = max(0LL, (c - a) / (len - cnt) - 2);
    long long ans = st + t * len;
    a -= t * cnt, c -= t * len;
    while (1){
        if (b >= x) b -= x; else a--, b = w - (x - b);
        c--;
        ans++;
        if (c <= a){printf("%I64d\n", ans); return 0;}
    }
}