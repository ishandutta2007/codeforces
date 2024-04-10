#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, p; fin >> n >> p;
    multiset<array<ll, 3>> events;
    for (int i = 0; i < n; i++) {
        ll x; fin >> x;
        events.insert({x, 0, i});
    }
    deque<ll> q;
    vector<ll> res(n);
    multiset<ll> waiting, up;
    while (!events.empty()) {
        auto it = events.begin();
        auto a = *it; events.erase(it);
        if (a[1] == 0) {
            if (up.size() > 0 && *up.begin() < a[2])
                waiting.insert(a[2]);
            else {
                up.insert(a[2]);
                q.push_back(a[2]);
                if (q.size() == 1)
                    events.insert({a[0]+p, 1, a[2]});
            }
        }
        if (a[1] == 1) {
            res[q.front()] = a[0];
            up.erase(up.find(q.front()));
            q.pop_front();
            if (waiting.size() > 0 && (up.size() == 0 || *up.begin() > *waiting.begin())) {
                auto it2 = waiting.begin();
                up.insert(*it2);
                q.push_back(*it2);
                waiting.erase(it2);
            }
            if (q.size() > 0)
                events.insert({a[0]+p, 1, q.front()});
        }
    }
    for (auto& x : res) cout << x << " ";
    cout << "\n";
}