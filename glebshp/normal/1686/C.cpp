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

const int maxn = 100 * 1000 + 100;

int a[maxn];
int res[maxn];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    scanf("%d", &tnum);
    for (int tc = 0; tc < tnum; tc++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        if (n % 2 == 1) {
            cout << "NO" << endl;
            continue;
        }

        sort(a, a + n);
        
        int cur = 0;
        for (int i = 0; i < n / 2; i++) {
            res[cur] = a[n / 2 + i];
            cur = (cur + 2) % n;
        }

        cur = n - 3;
        for (int i = n / 2 - 1; i >= 0; i--) {
            res[cur] = a[i];
            cur = (cur + n - 2) % n;
        }

        bool flag = true;
        for (int i = 0; i < n; i++) {
            int prv = (i + n - 1) % n;
            int nxt = (i + 1) % n;
            if (!((res[prv] > res[i] && res[i] < res[nxt]) || (res[prv] < res[i] && res[i] > res[nxt]))) {
                flag = false;
            }
        }

        if (flag) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << res[i] << ' ';
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}