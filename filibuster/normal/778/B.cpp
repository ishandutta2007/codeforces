#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 350;

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    map<string, int> mp;
    vector<pair<int, pii>> a(n);
    vector<string> val(n);

    mp["?"] = n;
    for(int i = 0; i < n; i++) {
        string name;
        cin >> name;

        s[i] = name;
        mp[name] = i;

        string t;
        cin >> t;
        cin >> t;

        if('0' <= t[0] && t[0] <= '1') {
            val[i] = t;
        } else {
            a[i].s.f = mp[t];
//            cout << i << ' ' << t << ' ' << mp[t] << endl;
            cin >> t;

            if(t[0] == 'A')
                a[i].f = 1;
            else if(t[0] == 'O')
                a[i].f = 2;
            else
                a[i].f = 3;

            cin >> t;

            a[i].s.s = mp[t];
        }
    }

//    for(int i = 0; i < n; i++) {
//        cout << s[i] << ' ';
//        if(a[i].f == 0)
//            cout << val[i] << endl;
//        else
//            cout << a[i].f << ' ' << a[i].s.f << ' ' << a[i].s.s << endl;
//    }

    string mx = "", mn = "";

    for(int i = 0; i < m; i++) {

        vector<int> res(n + 1, -1);
        vector<int> ans(2, 0);
        for(res[n] = 0; res[n] <= 1; res[n]++) {
            for(int j = 0; j < n; j++) {
                if(a[j].f == 0) {
                    res[j] = val[j][i] - '0';
                } else {
                    if(a[j].f == 1) {
                        res[j] = res[a[j].s.f] & res[a[j].s.s];
                    } else if(a[j].f == 2) {
                        res[j] = res[a[j].s.f] | res[a[j].s.s];
                    } else {
                        res[j] = res[a[j].s.f] ^ res[a[j].s.s];
                    }
                }

                ans[res[n]] += res[j];
            }
        }

        if(ans[0] >= ans[1])
            mx += '0';
        else
            mx += '1';

        if(ans[0] <= ans[1])
            mn += '0';
        else
            mn += '1';
    }

    cout << mn << endl << mx << endl;
}