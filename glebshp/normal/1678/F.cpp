#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int maxn = 1000 * 1000 + 100;
const int mdl = 998244353;

int v[maxn];
int n;
int k;
int tnum;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &tnum);
    for (int tc = 0; tc < tnum; tc++) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }

        bool flag = true;
        for (int i = n - k; i < n; i++) {
            if (v[i] != 0 && v[i] != -1) {
                flag = false;
            }
        }
        if (!flag) {
            printf("0\n");
            continue;
        }

        long long ans = 1ll;
        for (int i = 1; i <= k; i++) {
            ans = (ans * i) % mdl;
        }
        for (int i = 0; i < n - k; i++) {
            if (v[i] == -1) {
                ans = (ans * (i + k + 1)) % mdl;
            }
            if (v[i] == 0) {
                ans = (ans * (k + 1)) % mdl;
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}