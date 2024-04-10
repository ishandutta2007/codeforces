#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 70005;
int t[N], o[N];
pair<int, int> a[N];
bitset<N> b[N/4], temp[4], r;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, s; cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first; a[i].second = i;
    }
    sort(a, a+n, greater<>());
    r[0] = 1;
    b[0][0] = 1;
    for (int i = 1; i < n; i++) {
        r = (r<<a[i].first)|r;
        if (i%4 == 0) b[i/4] = r;
    }
    s -= a[0].first;
    if (s < 0 || !r[s])
        return cout << "-1\n", 0;
    int k = n;
    while ((k-1)%4 != 0) k++;
    for (int i = k-1; i > 0; i--) {
        if (i%4 == 0) {
            temp[0] = b[(i-1)/4];
            temp[1] = (temp[0]<<a[i-3].first)|temp[0];
            temp[2] = (temp[1]<<a[i-2].first)|temp[1];
            temp[3] = (temp[2]<<a[i-1].first)|temp[2];
        }
        if (a[i].first <= s && temp[(i-1)%4][s-a[i].first])
            s -= a[i].first, t[i] = 1;
    }
    int p = inf;
    for (int i = 0; i < n; i++)
        o[a[i].second] = i;
    for (auto& i : vector(o, o+n)) {
        if (i != n-1 && !t[i+1])
            cout << a[i].first-a[i+1].first << " 1 " << a[i+1].second+1 << "\n";
        else
            cout << a[i].first << " 0\n";
    }
}