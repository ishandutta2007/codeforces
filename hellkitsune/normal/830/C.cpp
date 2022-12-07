#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
LL k;
int a[100];
vector<int> all;

bool check(LL x) {
    LL have = 0;
    forn(i, n) {
        LL cur = x - a[i] % x;
        if (cur == x) cur = 0;
        have += cur;
    }
    return have <= k;
}

void bs(LL from, LL to) {
    LL mid;
    while (from < to) {
        mid = (from + to + 1) / 2;
        if (check(mid)) {
            from = mid;
        } else {
            to = mid - 1;
        }
    }
    cout << from << endl;
}

int main() {
//    freopen("input.txt", "r", stdin);
    if (0) {
        mt19937 mt(123);
        n = 100;
        k = LL(1e11);
        forn(i, n) a[i] = mt() % int(1e9) + 1;
    } else {
        cin >> n >> k;
        forn(i, n) scanf("%d", a + i);
    }
    int cur = 1;
    forn(z, n) {
        int val = a[z];
        int i = 1;
        int rem = 5;
        while (rem > 0) {
            if (i == cur) {
                all.push_back(i);
                ++cur;
            }
            all.push_back((val + i - 1) / i);
            ++i;
            if (i * i > val) {
                --rem;
            }
        }
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    if (check(all.back())) {
        bs(all.back(), LL(3e11));
        return 0;
    }
    int from = 1;
    int to = all[0] - 1;
    forn(i, (int)all.size() - 1) {
        if (check(all[i])) {
            from = all[i];
            to = all[i + 1] - 1;
        }
    }
    bs(from, to);
    return 0;
}