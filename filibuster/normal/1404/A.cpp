#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int A = 26;

/*
1
2
2 2
*/

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for(int i = 0; i < k; i++) {
        char c = '?';
        for(int j = i; j < n; j += k) {
            if(s[j] == '?' || c == s[j])
                continue;

            if(c == '?') {
                c = s[j];
            } else {
                cout << "NO" << endl;
                return;
            }
        }

        for(int j = i; j < n; j += k)
            s[j] = c;

    }

    int c0 = 0, c1 = 0, c = 0;
    for(int i = 0; i < k; i++) {
        if(s[i] == '0')
            c0++;
        else if(s[i] == '1')
            c1++;
        else
            c++;
    }



    cout << (abs(c0 - c1) <= c ? "YES" : "NO") << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}