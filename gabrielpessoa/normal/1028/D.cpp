#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int ms = 3e5+5;
const ll mod = 1e9+7;
const ll inf = 308983067ll;

set<ll> buy, sell;
set<ll> mistery;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    ll maior = 0, menor = inf;
    buy.insert(inf); sell.insert(inf);
    ll ans = 1;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll x;
        cin >> x;
        if(s == "ADD") {
            if(x < maior) {
                buy.insert(inf-x);
            } else if(x > menor) {
                sell.insert(x);
            } else {
                mistery.insert(x);
            }
        } else {
            if(x == maior) {
                buy.erase(inf - maior);
                for(ll y : mistery) {
                    sell.insert(y);
                }
                mistery.clear();
            } else if(x == menor) {
                sell.erase(menor);
                for(ll y : mistery) {
                    buy.insert(inf-y);
                }
                menor = *sell.begin();
            } else if(mistery.count(x)) {
                mistery.erase(x);
                ans = (ans * 2) % mod;
                for(ll y : mistery) {
                    if(y < x) buy.insert(inf-y);
                    else sell.insert(y);
                }
            } else {
                cout << 0 << '\n';
                return 0;
            }
            menor = *sell.begin();
            maior = inf - (*(buy.begin()));
            mistery.clear();
        }
    }
    ll ansLL = ans;
    if(!mistery.empty()) {
        ansLL = (ansLL) * (1 + mistery.size()) % mod;
    }
    cout << ansLL << '\n';
}