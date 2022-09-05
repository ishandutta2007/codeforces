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

typedef long long ll;



int main() {
	int n, m;
    scanf("%d%d", &n, &m);
    vector<pair<int,int>> in(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &in[i].first, &in[i].second);
    }
    vector<long long> answer(n);
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        int s = min(in[a].first + in[b].second, in[a].second + in[b].first);
        answer[a] -= s;
        answer[b] -= s;
    }
    debug() << imie(answer);
    vector<int> indices(n);
    for(int i = 0; i < n; ++i) {
        indices[i] = i;
    }
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return in[a].first - in[a].second < in[b].first - in[b].second;
    });
    
    for(int rep = 0; rep < 2; ++rep) {
        long long sum = 0;
        for(int i = 0; i < (int) indices.size(); ++i) {
            int id = indices[i];
            answer[id] += sum + i * 1LL * in[id].second;
            sum += in[id].first;
        }
        reverse(indices.begin(), indices.end());
        for(auto& p : in) {
            swap(p.first, p.second);
        }
    }
        
    for(auto x : answer) {
        printf("%lld ", x);
    }
    puts("");
}