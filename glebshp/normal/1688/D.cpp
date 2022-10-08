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

const int maxn = 300 * 1000 + 100;

int a[maxn];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    scanf("%d", &tnum);

    for (int tc = 0; tc < tnum; tc++) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        if (k < n) {
            long long sum = 0ll;
            long long maxsum;
            for (int i = 0; i < k; i++) {
                sum += a[i];
            }
            maxsum = sum;
            for (int i = 0; i + k < n; i++) {
                sum -= a[i];
                sum += a[i + k];
                maxsum = max(maxsum, sum);
            }
            cout << maxsum + k * 1ll * (k - 1) / 2 << endl;
        } else {
            long long sum = 0ll;
            for (int i = 0; i < n; i++) {
                sum += a[i];
            }
            cout << sum + k * 1ll * n - n * 1ll * (n + 1) / 2 << endl;
        }
    }

    return 0;
}