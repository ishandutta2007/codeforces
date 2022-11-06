#include <bits/stdc++.h>

// Contest: Codeforces Round #600 (Div. 2) (https://codeforces.com/contest/1253)
// Problem: B: Silly Mistake (https://codeforces.com/contest/1253/problem/B)

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

arr<bool, 1'000'000> in;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int c = 0, cnt = 0;
    vi part;
    set<int> seen;
    while (n--) {
        int e; cin >> e;
        ++c;
        if ((e > 0 && in[e]) || (e < 0 && !in[-e]) || (e > 0 && seen.find(e) != end(seen))) {
            cout << "-1\n";
            return 0;
        }
        if (e > 0)
            in[e] = true, ++cnt;
        else
            in[-e] = false, --cnt, seen.emplace(-e);
        if (cnt == 0)
            part.push_back(c), c = 0, seen.clear();
    }

    if (cnt) { cout << "-1\n"; return 0; }
    if (c)
        part.push_back(c);
    cout << part.size() << '\n';
    for (auto i : part)
        cout << i << ' ';
    cout << '\n';

    return 0;
}