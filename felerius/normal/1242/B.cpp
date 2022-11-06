#include <bits/stdc++.h>

// Contest: Codeforces Round #599 (Div. 1) (https://codeforces.com/contest/1242)
// Problem: B: 0-1 MST (https://codeforces.com/contest/1242/problem/B)

using namespace std;

template <class T, size_t... Is> struct arr_helper;
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<arr<T, Is...>, I>; };

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using vpi = vector<pi>;

struct DSF {
    vector<int> p;

    DSF(int n) : p(n) {
        iota(begin(p), end(p), 0);
    }

    int find(int v) {
        if (p[v] != v)
            return p[v] = find(p[v]);
        return v;
    }

    void merge(int a, int b) {
        a = find(a), b = find(b);
        p[a] = b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> exp(n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        exp[a].push_back(b);
        exp[b].push_back(a);
    }

    set<int> blocked(begin(exp[0]), end(exp[0]));
    set<int> avail;
    for (int i = 1; i < n; ++i)
        avail.emplace(i);
    int cost = 0;
    for (int i = 1; i < n; ++i) {
        auto ita = begin(avail), itb = begin(blocked);
        while (ita != end(avail) && itb != end(blocked) && *ita == *itb)
            ita++, itb++;
        int v;
        if (ita == end(avail)) {
            ++cost;
            v = *begin(avail);
        } else
            v = *ita;

        set<int> blocked_next;
        for (auto vb : exp[v])
            if (blocked.find(vb) != end(blocked))
                blocked_next.emplace(vb);
        blocked = blocked_next;
        avail.erase(v);
    }

    cout << cost << '\n';
    return 0;
}