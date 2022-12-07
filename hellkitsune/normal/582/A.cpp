#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
multiset<int, greater<int> > se;
vector<int> ans;

int gcd(int x, int y) {
    while (y) x %= y, swap(x, y);
    return x;
}

int main() {
    scanf("%d", &n);
    REP(i, n * n) {
        int x;
        scanf("%d", &x);
        se.insert(x);
    }
    REP(i, n) {
        int x = *se.begin();
        se.erase(se.begin());
        for (int y : ans) {
            int cur = gcd(x, y);
            auto it = se.find(cur);
            se.erase(it);
            it = se.find(cur);
            se.erase(it);
        }
        ans.pb(x);
    }
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}