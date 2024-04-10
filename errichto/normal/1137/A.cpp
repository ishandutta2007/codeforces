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

void max_self(int& a, int b) {
    a = max(a, b);
}

int main() {
    int h, w;
    scanf("%d%d", &h, &w);
    vector<vector<int>> a(h, vector<int>(w));
    auto smaller = a;
    auto bigger = a;
    for(int row = 0; row < h; ++row) {
        for(int col = 0; col < w; ++col) {
            scanf("%d", &a[row][col]);
        }
    }
    for(int row = 0; row < h; ++row) {
        vector<pair<int,int>> values;
        for(int col = 0; col < w; ++col) {
            values.emplace_back(a[row][col], col);
        }
        sort(values.begin(), values.end());
        for(int rep = 0; rep < 2; ++rep) {
            int cnt = 0;
            for(int i = 0; i < (int) values.size(); ++i) {
                int col = values[i].second;
                if(rep == 0) {
                    max_self(smaller[row][col], cnt);
                }
                else {
                    max_self(bigger[row][col], cnt);
                }
                if(i < (int) values.size() - 1 && values[i].first != values[i+1].first) {
                    ++cnt;
                }
            }
            reverse(values.begin(), values.end());
        }
    }
    swap(h, w);
    for(int row = 0; row < h; ++row) {
        vector<pair<int,int>> values;
        for(int col = 0; col < w; ++col) {
            values.emplace_back(a[col][row], col);
        }
        sort(values.begin(), values.end());
        for(int rep = 0; rep < 2; ++rep) {
            int cnt = 0;
            for(int i = 0; i < (int) values.size(); ++i) {
                int col = values[i].second;
                if(rep == 0) {
                    max_self(smaller[col][row], cnt);
                }
                else {
                    max_self(bigger[col][row], cnt);
                }
                if(i < (int) values.size() - 1 && values[i].first != values[i+1].first) {
                    ++cnt;
                }
            }
            reverse(values.begin(), values.end());
        }
    }
    swap(h, w);
    for(int row = 0; row < h; ++row) {
        for(int col = 0; col < w; ++col) {
            printf("%d", smaller[row][col] + bigger[row][col] + 1);
            if(col != w - 1) {
                printf(" ");
            }
        }
        puts("");
    }
}