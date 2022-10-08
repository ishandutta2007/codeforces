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

int tc;
long long n;

int bitcount(long long x) {
    int cnt = 0;
    while (x > 0) {
        cnt += x % 2;
        x /= 2;
    }

    return cnt;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &tc);
    for (int tnum = 0; tnum < tc; tnum++) {
        scanf("%lld", &n);

        int ans = bitcount(n);

        vector <long long> facts;
        long long val = 6;
        int cur = 4;
        while (val <= n) {
            facts.pb(val);
            val *= cur;
            cur++;    
        }

        int m = facts.size();
        for (int i = 0; i < (1 << m); i++) {
            int h = 0;
            long long sum = 0ll;
            for (int j = 0; j < m; j++) {
                if ((i >> j) & 1) {
                    h++;
                    sum += facts[j];
                }
            }
            if (sum <= n) {
                ans = min(ans, h + bitcount(n - sum));
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}