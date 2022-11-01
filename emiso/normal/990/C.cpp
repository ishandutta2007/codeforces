#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN];
char s[MN]; string str;

map<int, ll> seq;

int main() {
    scanf("%lld", &n);

    for(int b = 0; b < n; b++) {
        scanf("%s", s); str = s;

        int tL = 0, tR = 0, val = 0;
        for(int i = 0; i < str.size(); i++) {
            val += (str[i] == '(') ? 1 : -1;
            if(val < 0) tL = 1;
        }
        val = 0;
        for(int i = ((int)str.size())-1; i >= 0; i--) {
            val += (str[i] == '(') ? 1 : -1;
            if(val > 0) tR = 1;
        }

        if(tL && tR) continue;
        seq[val]++;
    }

    for(auto &p : seq) {
        if(p.first < 0) continue;
        ans += (p.second * seq[-p.first]);
    }

    printf("%lld\n", ans);
    return 0;
}