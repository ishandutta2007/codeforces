#include <bits/stdc++.h>

using namespace std;

#define MN 100010
#define MOD 1000000007

int expo(int a, int b) {
    if(!b) return 1;
    if(b & 1) return 1LL * a * expo(1LL * a * a % MOD, b >> 1) % MOD;
    return expo(1LL * a * a % MOD, b >> 1);
}

vector<int> divi[MN];
int n, ans;

int main() {
    int tmp = 0;
    for(int x = 1; x < MN; x++) {
        vector<int> v;
        for(int d = 1; d * d <= x; d++) {
            if(x % d == 0) {
                divi[x].push_back(d);
                if(d * d < x) v.push_back(x / d);
            }
        }

        reverse(v.begin(), v.end());
        for(int d : v) divi[x].push_back(d);
        tmp += divi[x].size();
    }

    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());

    for(int lcm = 1; lcm < MN; lcm++) {
        int tmp = 1;
        auto last = v.begin();
        for(int i = 0; i + 1 < divi[lcm].size(); i++) {
            int d = divi[lcm][i], nd = divi[lcm][i+1];
            auto now = lower_bound(v.begin(), v.end(), nd);
            tmp = 1LL * tmp * expo(i + 1, now - last) % MOD;
            last = now;
        }

        int geq = v.end() - last;
        int z = (0LL + expo(divi[lcm].size(), geq) - expo(divi[lcm].size()-1, geq) + MOD);
        if(z >= MOD) z -= MOD;
        tmp = 1LL * tmp * z % MOD;

        ans += tmp;
        if(ans >= MOD) ans -= MOD;
    }

    printf("%d\n", ans);
    return 0;
}