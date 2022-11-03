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

    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    int l = 0, r = n;
    while(r - l > 1) {
        int mid = (l + r) / 2;

        vector<bool> b(n, true);
        for(int i = 0; i < mid; i++)
            b[a[i]] = false;



        int cur = 0;
        for(int i = 0; i < n && cur < m; i++) {

            if(b[i] && s[i] == t[cur])
                cur++;
        }

//        cout << l << ' ' << mid << ' ' << r << ' ' << cur << endl;

        if(cur == m)
            l = mid;
        else
            r = mid;
    }

    cout << l << endl;
}