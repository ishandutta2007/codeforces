#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[50000];
multiset<int> se;
vector<int> curAns;
vector<int> bestAns;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    int lo = 1, hi = 1000000001, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        se.clear();
        curAns.clear();
        forn(i, n) {
            int x = a[i];
            while (x > mid) x /= 2;
            se.insert(-x);
        }
//        if (mid == 3) {
//            for (int x : se) cerr << x << ' ';
//            cerr << endl;
//        }
        bool ok = true;
        while (!se.empty()) {
            int v = -(*se.begin());
            se.erase(se.begin());
            if (!se.empty() && v == -(*se.begin())) {
                if (v == 1) {
                    ok = false;
                    break;
                }
                se.insert(- (v / 2));
            } else {
                curAns.pb(v);
            }
        }
        if (ok) {
            hi = mid;
            bestAns = curAns;
        } else {
            lo = mid + 1;
        }
    }
    for (int x : bestAns) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}