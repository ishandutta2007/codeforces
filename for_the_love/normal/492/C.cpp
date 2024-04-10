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


struct Node{
    int a, b;
    bool operator < (const Node &A)const{
        return b < A.b;
    }
} p[N];

int main() {
    int n, r; LL avg, cur = 0;
    cin >> n >> r >> avg;
    for (int i = 0; i < n; i++){
        scanf("%d%d", &p[i].a, &p[i].b);
        cur += p[i].a;
    }
    sort(p, p + n);

    avg *= n;

    LL ans = 0;
    if (cur < avg)
    for (int i = 0; i < n; i++){
        LL t = min(avg - cur, 1LL * r - p[i].a);
        cur += t;
        ans += t * p[i].b;
        if (cur == avg) break;
    }

    cout << ans << endl;

}