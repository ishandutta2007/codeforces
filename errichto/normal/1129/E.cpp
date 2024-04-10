#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;

const int nax = 505;
int subtree[nax];

int query(vector<int> a, vector<int> b, int c) {
    printf("%d\n", (int) a.size());
    for(int x : a) {
        printf("%d ", x);
    }
    puts("");
    printf("%d\n", (int) b.size());
    for(int x : b) {
        printf("%d ", x);
    }
    puts("");
    printf("%d\n", c);
    debug() << imie(a) imie(b) imie(c);
    fflush(stdout);
    int r;
    scanf("%d", &r);
    return r;
}

int main() {
    int n;
    scanf("%d", &n);
    subtree[1] = n;
    for(int a = 2; a <= n; ++a) {
        vector<int> vec;
        for(int i = 2; i <= n; ++i) {
            vec.push_back(i);
        }
        subtree[a] = query({1}, vec, a);
    }
    vector<int> they;
    for(int a = 1; a <= n; ++a) {
        they.push_back(a);
    }
    sort(they.begin(), they.end(), [&](int a, int b) {
        return subtree[a] < subtree[b];
    });
    vector<pair<int,int>> edges;
    vector<bool> done(n + 1);
    vector<int> already(n + 1);
    debug() << imie(they);
    for(int ii = 0; ii < (int) they.size(); ++ii) {
        int a = they[ii];
        while(already[a] + 1 < subtree[a]) {
            debug() << imie(a) imie(subtree[a]) imie(already[a]);
            vector<int> below;
            for(int i = 0; i < ii; ++i) {
                int x = they[i];
                if(!done[x]) {
                    below.push_back(x);
                }
            }
            assert(!below.empty());
            int low = 0, high = (int) below.size() - 1;
            while(low < high) {
                int m = (low + high) / 2;
                vector<int> only;
                for(int i = 0; i <= m; ++i) {
                    only.push_back(below[i]);
                }
                if(query({1}, only, a) >= 1) {
                    high = m;
                }
                else {
                    low = m + 1;
                }
            }
            int child = below[low];
            done[child] = true;
            already[a] += subtree[child];
            edges.emplace_back(a, child);
            debug() << imie(a) imie(child);
        }
    }
    puts("ANSWER");
    for(pair<int,int> p : edges) {
        printf("%d %d\n", p.first, p.second);
    }
    fflush(stdout);
}