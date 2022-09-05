#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int m;
ll sk, sb, tot;

int main() {
    scanf("%lld %d", &tot, &m);
    vector<array<ll, 2>> st = {{0, 0}};
    auto chk = [&](array<ll, 2> p, array<ll, 2> q, array<ll, 2> r) {
        return (__int128)(q[0] - p[0]) * (r[1] - q[1]) < (__int128)(q[1] - p[1]) * (r[0] - q[0]);
    };
    while (m--) {
        int op, k, b;
        scanf("%d %d", &op, &k);
        if (op == 1) {
            st.resize(1), sk = sb = 0, tot += k;
        } else if (op == 2) {
            array<ll, 2> p{tot, -tot * sk - sb};
            while (st.size() > 1 && chk(st[st.size() - 2], st.back(), p)) st.pop_back();
            st.push_back(p), tot += k;
        } else {
            scanf("%d", &b);
            sk += b, sb += k;
        }
        auto eval = [&](int i) { return sk * st[i][0] + st[i][1] + sb; };
        while (st.size() > 1 && eval(st.size() - 1) >= eval(st.size() - 2)) st.pop_back();
        printf("%lld %lld\n", st.back()[0] + 1, eval(st.size() - 1));
    }
    return 0;
}