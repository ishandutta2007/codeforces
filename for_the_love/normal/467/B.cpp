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
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int x[N];
int main(){
    int n, m, k, ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i <= m; i++) scanf("%d", &x[i]);
    for (int i = 0; i < m; i++){
        int cnt = 0;
        for (int j = 0; j < n; j++)
        if ((x[i] ^ x[m]) >> j & 1) cnt++;
        if (cnt <= k) ans++;
    }
    printf("%d\n", ans);

}