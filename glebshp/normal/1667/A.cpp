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

const int maxn = 5010;

long long a[maxn];
long long dp[maxn];
int n;


int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = -1;
    for (int i = 0; i < n; i++) {
        long long cur = 0ll;
        long long lst = 0ll;
        for (int j = i + 1; j < n; j++) {
            long long d = lst / a[j];
            if (d * a[j] <= lst) {
                d++;
            }    
            cur += d;
            lst = d * a[j];
        }
        lst = 0ll;
        for (int j = i - 1; j >= 0; j--) {
            long long d = -lst / a[j];
            if (d * a[j] <= -lst) {
                d++;
            }
            cur += d;
            lst = - d * a[j];
        }
        if (ans == -1 || ans > cur) {
            ans = cur;
        }
    }

    cout << ans << endl;

    return 0;
}