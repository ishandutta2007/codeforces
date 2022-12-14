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
const int maxn = 111111;
char buf[maxn], str[maxn];
int c[maxn];
int n;
vector<int> g[maxn];

struct Node{
    LL x, y;
    Node(LL _x = 0, LL _y = 0):x(_x), y(_y){}
}f[1111];

int main(){
    scanf("%s", buf + 1);
    int len = strlen(buf + 1);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%s", str);
        c[i] = str[0] - '0';
        g[i].clear();
        int L = strlen(str);
        for (int j = 3; j < L; ++j)
            g[i].push_back(str[j] - '0');
    }
    for (int i = 0; i < 10; ++i){
        f[i].x = 10;
        f[i].y = i;
    }
    for (int i = n - 1; i >= 0; --i){
        Node tmp(1, 0);
        for (int j = 0; j < sz(g[i]); ++j){
            tmp.y = tmp.y * f[g[i][j]].x % mo;
            tmp.y = (tmp.y + f[g[i][j]].y) % mo;
            tmp.x = (tmp.x * f[g[i][j]].x) % mo;
        }
        f[c[i]] = tmp;
    }
    LL ans = 0;
    for (int i = 1; i <= len; ++i){
        int t = buf[i] - '0';
        ans = ans * f[t].x % mo;
        ans = (ans + f[t].y) % mo;
    }
    printf("%d\n", (int)ans);
    return 0;
}