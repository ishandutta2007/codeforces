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

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


LL a[N], b[N];
inline LL go(LL x, LL y){
    while (y != 0){
        if (y < 0){
            x /= 2;
            y++;
        }else{
            x *= 2;
            y--;
        }
    }
    return x;
}

map <LL, int> S;

inline int get(LL x, LL y){
    int step = 0;
    while (x){
        if (x <= y && y % x == 0 && S.find(y / x) != S.end())
            return step + S[y / x];
        step++;
        x /= 2;
    }
    return -1;
}

map <LL, int> vis;

int main(){
    for (int i = 0; i < 36; i++)
        S[1LL << i] = i;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    int ans = INF;

    for (int i = 0; i < 18; i++)
    for (int j = 0; j < 18; j++){
        LL t = go(a[0], -i);
        if (t == 0) continue;
        t = go(t, j);
        if (vis[t]) continue;
        vis[t] = 1;
        int flag = 0, tot = i + j;
        for (int k = 1; k < n; k++){
            int p = get(a[k], t);
            if (p == -1){
                flag = 1;
                break;
            }
            tot += p;
            if (tot >= ans) break;
        }
        if (flag) continue;
        ans = min(ans, tot);
    }
    printf("%d\n", ans);
}