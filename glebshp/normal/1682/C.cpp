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

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    scanf("%d", &tnum);
    for (int tc = 0; tc < tnum; tc++) {
        int n;
        scanf("%d", &n);

        map <int, int> cnt;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            cnt[x]++;
        }

        int ones = 0;
        int doubles = 0;
        for (const auto& e : cnt) {
            if (e.sc >= 2) {
                doubles++;
            }
            if (e.sc == 1) {
                ones++;
            }            
        }
        int ans = doubles;
        if (ones > 0) {
            ans++;
            ones--;
        }
        printf("%d\n", ans + ones / 2);
    }

    return 0;
}