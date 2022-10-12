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

struct suffixarray {

    vector<int> s, a;

    // constructs a suffix array in O(nlogn) time, where K is the alphabet size.
    template<typename it>
    suffixarray(it first, it last) : s(first, last), a(last-first+1) {
        int n = s.size()+1, c = 1, j = 1, b;
        map<int, vector<int>> grp;
        vector<int> r(n), rc(n);
        for (int i = 0; i < n-1; i++)
            grp[s[i]].push_back(i);
        a[0] = n-1, r[n-1] = 0;
        for (auto& [_, v] : grp) {
            for (auto& i : v)
                r[i] = c, a[j++] = i;
            c++;
        }
        vector<vector<int>> cnt(n);
        for (int k = 1; k < 2*n; k <<= 1) {
            for (int i = 0; i < n; i++)
                cnt[r[b = (a[i]+2*n-k)%n]].push_back(b);
            c = -1, j = 0;
            for (auto& v : cnt) {
                for (int i = 0; i < v.size(); i++) {
                    if (i == 0 || r[(v[i]+k)%n] != r[(v[i-1]+k)%n]) c++;
                    rc[v[i]] = c, a[j++] = v[i];
                } v.clear();
            } swap(r, rc);
        } a.erase(a.begin());
    }

    suffixarray(string str) : suffixarray(str.begin(), str.end()) {}

    // returns a pair [l, r] such that all suffixes starting at
    // indices in the suffix array a[l..r] contain the input as a prefix,
    // runs in O(mlogn) time where m is the input size.
    template<typename it>
    pair<int, int> interval(it first, it last) const {
        auto cmp = [&](int p) {
            for (int i = 0; first+i != last; i++) {
                if (p+i >= s.size() || s[p+i] < first[i]) return -1;
                if (s[p+i] > first[i]) return 1;
            } return 0;
        };
        int m, l, x = 0, y = s.size();
        while (x < y)
            if (cmp(a[m = (x+y)/2]) == -1) x = m+1;
            else y = m;
        l = x, x = -1, y = s.size()-1;
        while (x < y)
            if (cmp(a[m = (x+y+1)/2]) == 1) y = m-1;
            else x = m;
        return {l, x};
    }

    pair<int, int> interval(string str) const {
        return interval(str.begin(), str.end());
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    suffixarray a(s);
    int n; cin >> n;
    while (n--) {
        int k; cin >> k;
        string t; cin >> t;
        auto [l, r] = a.interval(t);
        if (r-l+1 < k)
            cout << "-1\n";
        else {
            vector<int> p;
            for (int i = l; i <= r; i++)
                p.pb(a.a[i]);
            sort(all(p));
            int out = inf;
            for (int i = 0; i <= p.size()-k; i++)
                out = min(out, p[i+k-1]-p[i]+(int)t.size());
            cout << out << "\n";
        }
    }
}