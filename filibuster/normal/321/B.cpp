#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 100 + 13;

int a[N], atk[N], def[N];
int n, na = 0, nd = 0;

int get(int m) {
    int res = 0;

    for(int i = 0; i < m; i++)
        if(atk[m - i - 1] > a[i])
            return 0;
        else
            res += a[i] - atk[m - i - 1];

    return res;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int m;
    cin >> m >> n;

    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;

        if(s == "ATK") {
            cin >> atk[na++];
        } else {
            cin >> def[nd++];
        }
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    sort(atk, atk + na);
    sort(def, def + nd);

    int ans = 0;

    for(int cnt = 0; cnt < 1; cnt++) {
        bool fl = false;
        int res = 0;

        map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[a[i]]++;

        for(int i = 0; i < nd; i++) {
            auto it = mp.upper_bound(def[i]);

            if(it == mp.end()) {
                fl = true;
                break;
            }

            it->s--;

            if(it->s == 0)
                mp.erase(it);
        }

        if(fl)
            break;

        vector<int> b;
        for(auto p : mp) {
            for(int i = 0; i < p.s; i++)
                b.push_back(p.f);
        }

//        for(int b1 : b)
//            cout << b1 << ' ';
//        cout << endl;

        if(b.size() < na)
            break;

        reverse(b.begin(), b.end());

        for(int i = na - 1, j = 0; i >= 0; i--, j++) {
            if(b[j] < atk[i]) {
                fl = true;
                break;
            }

            res += b[j] - atk[i];
        }

        if(fl)
            break;

        for(int i = na; i < b.size(); i++)
            res += b[i];

        ans = max(ans, res);
//        cout << "xfdbrh " << res << endl;
    }

    reverse(a, a + n);

    int l = 0, r = min(na, n) + 1;
    while(r - l > 1) {
        int mid = (l + r) / 2;

        if(get(mid) > 0)
            l = mid;
        else
            r = mid;
    }

    int sum1 = 0, sum2 = 0;

//    cout << r << endl;

    for(int i = 0; i < l; i++) {
        sum1 += a[i];
        sum2 += atk[i];

        ans = max(ans, sum1 - sum2);
    }

    cout << ans;
}