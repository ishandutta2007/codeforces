#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> ans;
bool pr[1005];

int main() {
    scanf("%d", &n);
    REP(i, 1005) pr[i] = true;
    for (int i = 2; i < 1005; ++i) if (pr[i]) {
        for (int j = i * i; j < 1005; j += i) {
            pr[j] = false;
        }
    }
    for (int i = 2; i <= n; ++i) if (pr[i]) {
        for (int j = i; j <= n; j *= i) {
            ans.pb(j);
        }
    }
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}