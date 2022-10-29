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
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int Getl(int l, int r, int p){
    int s = 1 << (p - 1), t = 1 << p;
    LL L = 0, R = INF; int ret = -1;
    while (L <= R){
        LL M = L + R >> 1;
        if (s + M * t >= l){
            if (s + M * t <= r) ret = M;
            R = M - 1;
        }else L = M + 1;
    }
    return ret * t + s;
}
int Getr(int l, int r, int p){
    int s = 1 << (p - 1);
    int t = 1 << p;
    LL L = 0, R = INF; int ret = -1;
    while (L <= R){
        LL M = L + R >> 1;
        if (s + M * t <= r){
            if (s + M * t >= l) ret = M;
            L = M + 1;
        }else R = M - 1;
    }
    return ret * t + s;
}
int main(){
    int l1, r1, l2, r2, ans = 0, x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    for (int i = 30; i > 0; i--){
        int L1 = Getl(l1, r1, i), R1 = Getr(l1, r1, i);
        int L2 = Getl(l2, r2, i), R2 = Getr(l2, r2, i);
        if (L1 == -1 || L2 == -1) continue;
        int t = (1 << (i - 1)) - 1;
        if (L1 + (1 << i) <= R1 - (1 << i)){
            x1 = y1 = x2 = y2 = t;
        }else{
            x1 = min(t, L1 - l1), y1 = min(t, r1 - L1);
            x2 = min(t, R1 - l1), y2 = min(t, r1 - R1);
        }

        if (L2 + (1 << i) <= R2 - (1 << i)){
            x3 = x4 = y3 = y4 = t;
        }else{
            x3 = min(t, L2 - l2), y3 = min(t, r2 - L2);
            x4 = min(t, R2 - l2), y4 = min(t, r2 - R2);
        }

        ans = max(ans, min(x1, x3) + min(y1, y3) + 1);
        ans = max(ans, min(x2, x3) + min(y2, y3) + 1);
        ans = max(ans, min(x1, x4) + min(y1, y4) + 1);
        ans = max(ans, min(x2, x4) + min(y2, y4) + 1);
    }
    cout << ans << endl;
}