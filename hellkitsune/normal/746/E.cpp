#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[200005];
set<int> was;
vector<int> pos;
int needOdd, needEven, remOdd, remEven;
vector<int> evens, odds;

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        scanf("%d", a + i);
    }
    remOdd = (m + 1) / 2;
    remEven = m / 2;
    needOdd = n / 2;
    needEven = n / 2;
    forn(i, n) {
        if (was.count(a[i])) {
            pos.pb(i);
        } else {
            was.insert(a[i]);
            if (a[i] % 2 == 0) {
                --needEven;
                if (a[i] <= m) {
                    --remEven;
                }
                evens.pb(i);
            } else {
                --needOdd;
                if (a[i] <= m) {
                    --remOdd;
                }
                odds.pb(i);
            }
        }
    }
    while (needOdd < 0) {
        ++needOdd;
        pos.pb(odds.back());
        odds.pop_back();
    }
    while (needEven < 0) {
        ++needEven;
        pos.pb(evens.back());
        evens.pop_back();
    }
    if (remOdd < needOdd || remEven < needEven) {
        cout << -1 << endl;
        return 0;
    }
    printf("%d\n", int(pos.size()));
    int cur = 1;
    while (needOdd) {
        while (was.count(cur)) {
            cur += 2;
        }
        --needOdd;
        a[pos.back()] = cur;
        pos.pop_back();
        cur += 2;
    }
    cur = 2;
    while (needEven) {
        while (was.count(cur)) {
            cur += 2;
        }
        --needEven;
        a[pos.back()] = cur;
        pos.pop_back();
        cur += 2;
    }
    forn(i, n) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}