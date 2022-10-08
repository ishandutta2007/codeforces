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
int n;
int x;

set <pair <long long, int> > original;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &tc);
    for (int tnum = 0; tnum < tc; tnum++) {
        original.clear();
        scanf("%d%d", &n, &x);
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            original.insert(mp(v, i));            
        }

        int ans = 0;
        while (!original.empty()) {
            pair <long long, int> minval = *original.begin();
            
            set <pair <long long, int> >::iterator it = original.lower_bound(mp(minval.fs * x, -1));
            if (it == original.end() || it->fs > minval.fs * x) {
                ans++;
                original.erase(minval);
            } else {
                original.erase(*it);
                original.erase(minval);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}