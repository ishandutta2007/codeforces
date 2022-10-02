#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_set>


using namespace std;


int n;
int a[40000];
int r[40000];


int main() {
    cin >> n;
    int s = (1 << (n + 1)) - 1;
    for (int i = 2; i <= s; i++) {
        cin >> a[i];
    }
    int g = (1 << (n));
    int ans = 0;
    for (int i = g; i < 2 * g; i++) {
        int ans1 = 0;
        int p = i;
        while (p != 1) {
            ans1 += a[p];
            p /= 2;
        }
        ans = max(ans, ans1);
        r[i - g] = ans1;
      //  cout << ans1 << endl;
    }
    int t = g / 2;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int k = 1000000000;
        int v = 0;
        for (int j = 0; j < g; j++) {
            k = min(k, ans - r[j]);
            v++;
            if (v == t) {
                sum += k;
               // cout << k << endl;
               // cout << j + 1 << endl;
                v = 0;
                for (int g1 = j - t + 1; g1 <= j; g1++) {
                    r[g1] += k;
                }
                k = 1000000000;
            }
        }
        t /= 2;
    }
    cout << sum << endl;
    return 0;
}