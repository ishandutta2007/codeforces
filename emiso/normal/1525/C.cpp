#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
template<typename... Args> void recInit(Args... args) {}
template<typename... Args> void recEnd(Args... args) {}
#define trace2(args...) trace(args)
#endif

ll t, n, m, ans[MN], a[MN];
char s[MN]; string str;

typedef pair<int, int> pii;

void cmon(vector<pii>& v, int i, int j, ll t, set<pair<ll, pii>>& coli) {
    if(v[i].first > 0 && v[j].first < 0) {
        int p1 = abs(v[i].first), p2 = abs(v[j].first);
        coli.insert({t + (p2 - p1)/2, {i, j}});
    }
    if(v[i].first < 0 && v[j].first < 0){
        int p1 = abs(v[i].first), p2 = abs(v[j].first);
        coli.insert({t + (p2 - p1 + p1 + p1)/2, {i, j}});
    }
    if(v[i].first > 0 && v[j].first > 0){
        int p1 = abs(v[i].first), p2 = abs(v[j].first);
        coli.insert({t + (p2 - p1 + (m - p2) + (m - p2))/2, {i, j}});
    }
    if(v[i].first < 0 && v[j].first > 0){
        int p1 = abs(v[i].first), p2 = abs(v[j].first);
        coli.insert({t + (m + p1 + (m - p2))/2, {i, j}});
    }
}

int main() {
    scanf("%lld", &t);
    st:

    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        ans[i] = -1;
    }

    vector<pii> odd, even;
    for(int i = 0; i < n; i++) {
        scanf("%s", &s);
        if(a[i] % 2) odd.push_back({a[i] * (s[0] == 'R' ? 1 : -1), i});
        else even.push_back({a[i] * (s[0] == 'R' ? 1 : -1), i});
    }
    sort(odd.begin(), odd.end(), [&](pii a, pii b){
         return abs(a.first) < abs(b.first);
    });
    sort(even.begin(), even.end(), [&](pii a, pii b){
         return abs(a.first) < abs(b.first);
    });

    for(auto v : {odd, even}) {
        set<int> rem;
        set<pair<ll, pii>> coli;
        for(int i = 0; i < (int)v.size(); i++) rem.insert(i);
        for(int i = 0; i + 1 < (int)v.size(); i++) {
            cmon(v, i, i+1, 0, coli);
        }
        while(rem.size() > 1) {
            auto topo = *coli.begin();
            coli.erase(topo);
            if(!rem.count(topo.second.first))  continue;
            if(!rem.count(topo.second.second)) continue;
            ans[v[topo.second.first].second] = topo.first;
            rem.erase(topo.second.first);
            ans[v[topo.second.second].second] = topo.first;
            rem.erase(topo.second.second);

            auto nxt = rem.lower_bound(topo.second.second);
            auto prv = rem.lower_bound(topo.second.first);
            if(nxt != rem.end() && prv != rem.begin()) {
                int R = *nxt, L = *prev(prv);
                cmon(v, L, R, 0, coli);
            }
        }
    }

    for(int i = 0; i < n; i++) printf("%lld ", ans[i]); puts("");
    if(--t) goto st;
    return 0;
}