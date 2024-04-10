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

const int maxn = 200 * 1000 + 100;

int tnum, n;
char s[maxn];
bool odd[maxn];
bool used[maxn];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &tnum);
    for (int tc = 0; tc < tnum; tc++) {
        scanf("%d", &n);
        scanf("%s", s);

        int oddcnt = 0;
        for (int i = 0; i < n; i++) {
            odd[i] = (s[i] == '1');
            oddcnt += odd[i];
        }
        if (oddcnt == 0 || oddcnt % 2 == 1) {
            printf("NO\n");
            continue;
        }

        vector <pair <int, int> > ansedges;
        for (int i = 0; i < n; i++) {
            used[i] = false;
        }

        int lst = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (odd[i]) {
                cnt++;                    
                if (cnt == oddcnt - 1) {
                    break;
                }
                if (lst == -1) {
                    lst = i;
                } else {
                    for (int j = lst; j < i; j++) {
                        ansedges.pb(mp(j, j + 1));
                        used[j] = true;
                    }
                    odd[i] = false;
                    lst = -1;
                }
            }
        }

        int fst = 0;
        lst = n - 1;
        while (!(odd[fst] && !used[fst])) {
            fst++;
        }
        while (!(odd[lst] && !used[lst])) {
            lst--;
        }
        vector <int> forder;
        for (int j = fst; j < lst; j++) {
            if (!used[j]) {
                forder.pb(j);
            }
        }
        for (int j = fst - 1; j >= 0; j--) {
            if (!used[j]) {
                forder.pb(j);
            }
        }
        for (int j = n - 1; j >= lst; j--) {
            if (!used[j]) {
                forder.pb(j);
            }
        }
        for (int j = 0; j < (int) forder.size() - 1; j++) {
            ansedges.pb(mp(forder[j], forder[j + 1]));
        }

        printf("YES\n");
        for (auto e : ansedges) {
            printf("%d %d\n", e.fs + 1, e.sc + 1);
        }
    }

    return 0;
}