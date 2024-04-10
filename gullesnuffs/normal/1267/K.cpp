#include <bits/stdc++.h>
using namespace std;

#define rep(i,f,t) for (int i = (f); i < (t); i++)
#define all(x) (x).begin(), (x).end()
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

map<int, int> fingerprint(ll x) {
    map<int, int> ret;
    for (int i = 2; x; i++) {
        ret[x%i]++;
        x /= i;
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    while(N--) {
        ll k;
        cin >> k;
        auto f = fingerprint(k);
        int maxD = 1;
        set<int> u;
        for (auto it : f) {
            u.insert(it.first);
            maxD += it.second;
        }
        u.erase(0);
        ll ans = -1;
        for (int removed : u) {
            --f[removed];
            ll comb = 1;
            int candidates = f[0];
            for (int d = 2; d < maxD; d++) {
                candidates += f[d-1];
                comb *= candidates;
                candidates--;
            }
            rep(d,0,maxD)
                rep(i,2,f[d]+1)
                    comb /= i;
            ans += comb;
            ++f[removed];
        }
        cout << ans << endl;
    }
}