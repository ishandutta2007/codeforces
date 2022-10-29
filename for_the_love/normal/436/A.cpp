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
const int N = 1e4 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int ans = 0, n, x, v[N], p[N], h[N], m[N];

void Solve(){
    int t = 0, cnt = 0, now = x;
    memset(v, 0, sizeof(v));
    while (1){
        int flag = 0, mx = -INF, node;
        for (int i = 1; i <= n; i++)
        if (!v[i] && p[i] == t && h[i] <= now && m[i] > mx){
            mx = m[i];
            node = i;
            flag = 1;
        }
        if (!flag) break;
        v[node] = 1;
        now += mx;
        cnt++;
        t ^= 1;
    }
    ans = max(ans, cnt);
}


int main(){
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &p[i], &h[i], &m[i]);
    Solve();
    for (int i = 1; i <= n; i++) p[i] ^= 1;
    Solve();
    cout << ans << endl;



}