#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

void solve(int tc) {
    int n;
    cin >> n;
    set<int> fire;
    set<pii> spells, spellsDouble;
    int lightnings = 0;
    ll damage = 0;
    while (n--) {
        int tp, d;
        cin >> tp >> d;
        
        damage += d;
        int leastSingle = spells.empty() ? 0 : spells.rbegin()->fi;
        if (d > 0) {
            if (!tp) fire.insert(d);
            else lightnings++;

            if (d > leastSingle) {
                damage += d;
                spellsDouble.emplace(d, tp);
            } else spells.emplace(d, tp);
        } else {
            d *= -1;
            if (!tp) fire.erase(d);
            else lightnings--;

            if (d > leastSingle) {
                damage -= d;
                spellsDouble.erase({d, tp});
            } else spells.erase({d, tp});
        }

        while (sz(spellsDouble) < lightnings) {
            auto it = --spells.end();
            damage += it->fi;
            spellsDouble.emplace(*it);
            spells.erase(it);
        }

        while (sz(spellsDouble) > lightnings) {
            auto it = spellsDouble.begin();
            damage -= it->fi;
            spells.emplace(*it);
            spellsDouble.erase(it);
        }

        int highestFire = fire.empty() ? 0 : *fire.rbegin();
        int leastDouble =
            spellsDouble.empty() ? 0 : spellsDouble.begin()->fi;
        if (highestFire < leastDouble) {
            cout << damage - leastDouble + highestFire << '\n';
        } else cout << damage << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}