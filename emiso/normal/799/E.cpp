#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll n, m, k, c[MN], L1[MN], L2[MN];

set<pair<ll, ll>> possib;
vector<pair<ll, ll>> no, o1, o2, both, nono;

ll ans = LLONG_MAX, cur = 0, n0 = 0, n1 = 0, n2 = 0, n12 = 0;

void put(int from) {
    if (from == 1) {
        possib.erase(o1.back());
        cur += o1.back().first;
        o1.pop_back();
        n1++;
    }
    else if (from == 2) {
        possib.erase(o2.back());
        cur += o2.back().first;
        o2.pop_back();
        n2++;
    }
    else if (from == 0) {
        cur += no.back().first;
        possib.erase(no.back());
        nono.push_back(no.back());
        no.pop_back();
        n0++;
    }
    else assert(false);
}

void rem(int from) {
    if (from == 0) {
        cur -= nono.back().first;
        possib.insert(nono.back());
        no.push_back(nono.back());
        nono.pop_back();
        n0--;
    }
    else if (from == 12) {
        cur -= both.back().first;
        both.pop_back();
        n12--;
    }
    else assert(false);
}

void upd() {
    //printf("%lld %lld %lld %lld | %lld %lld | %lld | %lld\n", n0, n1, n2, n12, n1 + n12, n2 + n12, n0 + n1 + n2 + n12, cur);
    if (n0 + n1 + n2 + n12 == m && n1 + n12 >= k && n2 + n12 >= k)
        ans = min(ans, cur);
}

int main() {   
    scanf("%lld %lld %lld", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &c[i]);
    }

    ll z;
    scanf("%lld", &z);
    for (int i = 0, y; i < z; i++) {
        scanf("%d", &y);
        L1[y] = 1;
    }
    scanf("%lld", &z);
    for (int i = 0, y; i < z; i++) {
        scanf("%d", &y);
        L2[y] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!L1[i] && !L2[i]) no.push_back({c[i], i});
        else if (L1[i] && !L2[i]) o1.push_back({c[i], i});
        else if (!L1[i] && L2[i]) o2.push_back({c[i], i});
        else both.push_back({c[i], i});
        possib.insert({c[i], i});
    }

    sort(no.rbegin(), no.rend());
    sort(o1.rbegin(), o1.rend());
    sort(o2.rbegin(), o2.rend());
    sort(both.begin(), both.end());

    for (auto tt : both) {
        possib.erase(tt);
        cur += tt.first; 
        n12++;
    }

    //printf("%lld\n", cur);

    while (n1 + n12 < k && !o1.empty()) put(1);
    while (n2 + n12 < k && !o2.empty()) put(2);
    while (n0 + n1 + n2 + n12 < m && !possib.empty()) {
        auto tt = *possib.begin();
        int i = tt.second;
        if (L1[i] && !L2[i]) put(1);
        else if (!L1[i] && L2[i]) put(2);
        else if (!L1[i] && !L2[i]) put(0);
        else assert(false);
    }
    while (n0 + n1 + n2 + n12 > m && !nono.empty()) {
        rem(0);
    }
    upd();

    while (!both.empty()) {
        rem(12);
        while (n1 + n12 < k && !o1.empty()) put(1);
        while (n2 + n12 < k && !o2.empty()) put(2);
        while (n0 + n1 + n2 + n12 < m && !possib.empty()) {
            auto tt = *possib.begin();
            int i = tt.second;
            if (L1[i] && !L2[i]) put(1);
            else if (!L1[i] && L2[i]) put(2);
            else if (!L1[i] && !L2[i]) put(0);
            else assert(false);
        }
        while (n0 + n1 + n2 + n12 > m && !nono.empty()) {
            rem(0);
        }
        upd();
    }

    printf("%lld\n", ans < LLONG_MAX ? ans : -1);
    return 0;
}