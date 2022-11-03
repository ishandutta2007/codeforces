#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    string s;
    int x;
    cin >> s >> x;

    int n = s.length();

    string t;
    for(int i = 0; i < n; i++)
        t += '2';

    for(int i = 0; i < n; i++) {
        int cnt = 0;

        if(i < x)
            cnt++;
        else if(s[i - x] == '1')
            cnt++;

        if(i + x >= n)
            cnt++;
        else if(s[i + x] == '1')
            cnt++;

        t[i] = (cnt == 2 ? '1' : '0');
    }

    string s1;
    for(int i = 0; i < n; i++)
        s1 += '0';

    for(int i = 0; i < n; i++) {
        if(i >= x && t[i - x] == '1')
            s1[i] = '1';
        if(i + x < n && t[i + x] == '1')
            s1[i] = '1';

    }

    if(s1 == s)
        cout << t << endl;
    else
        cout << -1 << endl;

//    for(int i = 0; i < n; i++) {
//        if(s[i] == '1') {
//            bool fl = false;
//            if(i >= x) {
//                if(t[i - x] == '1') {
//                    fl = true;
//                } else if(t[i - x] == '2') {
//                    fl = fl || (i < 2 * x || s[i - 2 * x] == '1');
//                    t[i - x] = '1';
//                }
//            }
//
//
//        } else {
//
//        }
//    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}