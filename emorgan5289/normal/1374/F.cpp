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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), r; for (auto& x : a) cin >> x;
        int s = 0, x = 0;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++) {
                if (a[i] == a[j]) s = 1;
                if (a[i] > a[j]) x++;
            }
        if (!s && (x&1)) {
            cout << "-1\n"; continue;
        }
        debug(a);
        int k = n-1;
        while (1) {
            while (k > 1 && a[k] >= a[k-1]) k--;
            if (k < 2) break;
            r.pb(k-2);
            swap(a[k-2], a[k]);
            swap(a[k-1], a[k]);
            if (k < n-1) k++;
        }
        int j = 0;
        k = lower_bound(a.begin()+1, a.end(), a[0])-a.begin()-1;
        debug(a, r);
        if (k&1 && k < n-1 && a[k+1] == a[0]) k++;
        if (k&1) {
            for (int i = 1; i < n-1; i++)
                if (a[i] == a[i+1]) {
                    while (j < i-1) {
                        r.pb(j); r.pb(j);
                        swap(a[j], a[j+2]);
                        swap(a[j], a[j+1]);
                        j += 2;
                    }
                    r.pb(i-1);
                    swap(a[i+1], a[i-1]);
                    swap(a[i+1], a[i]);
                    j++;
                    break;
                }
        }
        debug(a, r);
        while (j < k) {
            r.pb(j); r.pb(j);
            swap(a[j], a[j+2]);
            swap(a[j], a[j+1]);
            j += 2;
        }
        while (j > k) {
            r.pb(j-2);
            swap(a[j], a[j-2]);
            swap(a[j], a[j-1]);
            j -= 2;
        }
        debug(a, r);
        cout << r.size() << "\n";
        for (auto& i : r)
            cout << i+1 << " ";
        cout << "\n";
    }
}