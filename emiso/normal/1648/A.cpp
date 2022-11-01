#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll n, m;
//char s[MN]; string str;

vector<int> evr[MN], evc[MN];

int main() {
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; i++) {
        for (int j = 0, x; j < m; j++) {
            scanf("%d", &x);
            evr[x].push_back(i);
            evc[x].push_back(j);
        }
    }
    ll ans = 0;
    for (int i = 0; i <= 100000; i++) {
        vector<int> &tt = evr[i];
        sort(tt.begin(), tt.end());
        ll tmp = 0, sum = 0;
        for (auto pp : tt) {
            ans += (tmp * pp) - sum;
            sum += pp;
            tmp++;
        }
    }
    for (int i = 0; i <= 100000; i++) {
        vector<int> &tt = evc[i];
        sort(tt.begin(), tt.end());
        ll tmp = 0, sum = 0;
        for (auto pp : tt) {
            ans += (tmp * pp) - sum;
            sum += pp;
            tmp++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}