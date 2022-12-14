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

const int maxn = 111111;

bool g[maxn], f[maxn];
int c[maxn][27];
int n, k;
char buf[maxn];

int main(){
    scanf("%d%d", &n, &k);
    int tot = 1;
    for (int i = 0; i < n; ++i){
        scanf("%s", buf);
        int len = strlen(buf), u = 1;
        for (int j = 0; j < len; ++j){
            int t = buf[j] - 'a';
            if (c[u][t] == 0){
                c[u][t] = ++tot;
            }
            u = c[u][t];
        }
    }
    for (int i = tot; i >= 1; --i){
        f[i] = false;
        for (int j = 0; j < 26; ++j)
            if (c[i][j] && !f[c[i][j]]){
                f[i] = true;
                break;
            }
    }
    for (int i = tot; i >= 1; --i){
        int tt = 0, ss = 0;
        for (int j = 0; j < 26; ++j){
            if (c[i][j]){
                ++tt;
                if (g[c[i][j]]) ++ss;
            }
        }
        if (tt == 0 || (tt > ss)) g[i] = true;
    }
    if (!f[1]) puts("Second"); else {
        if (f[1] && g[1]) puts("First"); else {
            if (k & 1) puts("First"); else puts("Second");
        }
    }
    return 0;
}