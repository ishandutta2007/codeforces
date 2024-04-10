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

vector<pair<int, int>> out;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    out.pb({0, 0});
    for (int i = 0; i <= n; i++) {
        out.pb({2*i, 2*i+1});
        out.pb({2*i+1, 2*i});
        out.pb({2*i+2, 2*i});
        out.pb({2*i, 2*i+2});
        out.pb({2*i+2, 2*i+1});
        out.pb({2*i+1, 2*i+2});
        out.pb({2*i+2, 2*i+2});
    }
    cout << out.size() << "\n";
    for (auto& [i, j] : out)
        cout << i << " " << j << "\n";
}