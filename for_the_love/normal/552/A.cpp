#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <bitset>
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
const int N = int(1e5) + 9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int n, lx, ly, rx, ry;
int main() {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        ans += (rx - lx + 1) * (ry - ly + 1);
    }
    printf("%d\n", ans);
}