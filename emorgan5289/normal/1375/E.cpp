#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename it1, typename it2>
void compress(it1 first, it1 last, it2 result) {
    typedef typename remove_reference<decltype(*first)>::type T;
    map<T, vector<it2>> m;
    for (it1 i = first; i != last; i++)
        m[*i].push_back(result+(i-first));
    int t = 0;
    for (auto& [x, v] : m) {
        for (auto& i : v)
            *i = t;
        t++;
    }
}

template<typename it>
long long inversions(it first, it last) {

    typedef typename remove_reference<decltype(*first)>::type T;
    long long n = last-first, out = 0;
    vector<T> A(first, last), B(n);

    for (int w = 1; w < n; w <<= 1) {
        for (int k = 0; k < n;) {
            int s = k, j = k+w;
            for (int i = k; i < s+w && i < n; i++) {
                while (j < s+(w<<1) && j < n && A[j] < A[i])
                    B[k++] = A[j++];
                B[k++] = A[i], out += j-(s+w);
            }
            while (j < s+(w<<1) && j < n)
                B[k++] = A[j++];
        }
        swap(A, B);
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n), p(n); for (auto& x : a) cin >> x;
    vector<pair<int, int>> r;
    iota(all(p), 0);
    sort(all(p), [&](int i, int j){return a[i] == a[j] ? i < j : a[i] < a[j];});
    for (int i = 0; i < n; i++)
        a[p[i]] = i;
    vector<set<int>> v(n);
    for (int i = 0; i < n; i++)
        v[a[i]].insert(i);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (v[j].empty() || v[j+1].empty()) continue;
            auto x = --v[j].end(), y = v[j+1].begin();
            if (*x > *y) {
                r.emplace_back(*x, *y);
                v[j+1].insert(*x);
                v[j].insert(*y);
                v[j+1].erase(y);
                v[j].erase(x);
            }
        }
    }
    cout << r.size() << "\n";
    for (auto& [x, y] : r)
        cout << min(x, y)+1 << " " << max(x, y)+1 << "\n";
    // debug(r.size(), inversions(all(a)));
    // assert(r.size() == inversions(all(a)));
    // for (auto& [x, y] : r)
    //     swap(a[x], a[y]);
    // assert(is_sorted(all(a)));
}