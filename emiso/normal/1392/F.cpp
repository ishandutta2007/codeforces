#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

template<typename T>
struct fenwick_tree {
    vector<T> a;
    fenwick_tree(int n) {
        a.resize(n + 1);
    }
    fenwick_tree(vector<T> &vec) {
        a = vec;
        for(int i = 1; i < a.size(); i++)
            a[i + (i & -i)] += a[i];
    }
    void update(int idx, T delta) {
        for(; idx < a.size(); idx += (idx & -idx)) a[idx] += delta;
    }
    T query(int idx) {
        T ret = 0;
        for(; idx; idx -= (idx & -idx)) ret += a[idx];
        return ret;
    }
};

fenwick_tree<ll> bit(MN);
ll n, ans, a[MN];

ll get(int pos) {
    return a[pos] + bit.query(pos);
}

vector<int> eq;

int main() {
    scanf("%lld", &n);

    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        if(i <= 1) continue;

        ll last;
        if(a[i] == get(i-1) + 1) continue;

        while(!eq.empty()) {
            last = get(i-1);
            ll op = max(0LL, a[i] - last - 1);
            if(op == 0) break;
            int leq = eq.back(); eq.pop_back();
            op = min(i - leq, op);
            if(op == i - leq) {
                a[i] -= op;
                bit.update(leq, 1);
                bit.update(i, -1);
            } else {
                a[i] -= op;
                bit.update(leq, 1);
                bit.update(leq + op, -1);
                eq.push_back(leq + op);
            }
        }

        last = get(i-1);
        if(eq.empty() && (a[i] - last) >= i) {
            ll op = (a[i] - last) / i;
            bit.update(1, op);
            bit.update(i, -op);
            a[i] -= op * (i - 1);
        }
        last = get(i-1);
        if(a[i] == last) {
            eq.push_back(i);
        }
        if(eq.empty() && (a[i] - last) > 1) {
            bit.update(1, 1);
            bit.update((a[i] - last), -1);
            eq.push_back(a[i] - last);
            a[i] = last + 1;
        }
    }

    for(int i = 1; i <= n; i++)
        printf("%lld ", get(i));
    return 0;
}