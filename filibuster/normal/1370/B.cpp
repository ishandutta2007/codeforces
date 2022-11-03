#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2000 + 13;

int a[N];

void solve() {
    int n;
    cin >> n;

    set<int> od, ev;

    for(int i = 0; i < n * 2; i++) {
        cin >> a[i];

        if(a[i] % 2 == 0)
            ev.insert(i);
        else
            od.insert(i);
    }

    if(od.size() % 2 == 1) {
        od.erase(od.begin());
        ev.erase(ev.begin());
    } else {
        if(od.empty()) {
            ev.erase(ev.begin());
            ev.erase(ev.begin());
        } else {
            od.erase(od.begin());
            od.erase(od.begin());
        }
    }

    while(!od.empty()) {
        cout << *od.begin() + 1 << ' ';
        od.erase(od.begin());
        cout << *od.begin() + 1 << endl;
        od.erase(od.begin());
    }

    while(!ev.empty()) {
        cout << *ev.begin() + 1 << ' ';
        ev.erase(ev.begin());
        cout << *ev.begin() + 1 << endl;
        ev.erase(ev.begin());
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}