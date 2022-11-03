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
    int n;
    cin >> n;

    string s;
    cin >> s;

    string t = "";

    int mx = -1;
    for(int i = 0; i < n; i++)
        if(s[i] == '0')
            mx = i;

    int mn = n;
    for(int i = n - 1; i >= 0; i--)
        if(s[i] == '1')
            mn = i;

    if(mn == n || mx == -1 || mx < mn) {
        cout << s << endl;
        return;
    }

    for(int i = 0; i < mn; i++)
        t += s[i];
    for(int i = mx; i < n; i++)
        t += s[i];

//    int i;
//    for(i = 0; i < n; i++) {
//        if(s[i] == '0')
//            t += s[i];
//        else
//            break;
//    }
//
////    t += '0';
//
//    for(i = n - 1; i >= 1; i--) {
//        if(s[i] == '1')
//            t += s[i];
//        else
//            break;
//    }

    cout << t << endl;

//    for(int i = 0; i < n; i++) {
//        cin >> a[i];
//    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}