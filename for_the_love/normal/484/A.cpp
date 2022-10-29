#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<LL, LL> PI;

const DB eps = 1e-8;
const int N = 100 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

PI Get(LL x){
    PI ret = MP(0, -x);
    for (int i = 60; i >= 0; i--)
    if (x >> i & 1) ret.first ++;
    return ret;
}

int main(){
    int cas;
    LL a, b;
    scanf("%d", &cas);
    while (cas--){
        scanf("%I64d%I64d", &a, &b);
        PI ans = max(Get(b), Get(a));

        LL x = 0;

        for (int i = 60; i >= 0; i--)
        if (b >> i & 1){
            if (x + (1LL << i) - 1 >= a) ans = max(ans, Get(x + (1LL << i) - 1));
            x += (1LL << i);
        }
        cout << -ans.second << endl;
    }
}