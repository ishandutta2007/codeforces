#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int K = 20;

/*
5 10
99.99
*/

int cnt[1 << K];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int ind = 0; ind < n; ind++) {
        char c;
        cin >> c;

        string s;
        cin >> s;

        int x = 0;
        int p = 1;
        for(int i = s.length() - 1; i >= 0; i--) {
            x += (s[i] - '0') % 2 * p;
            p *= 2;
        }

        if(c == '+' || c == '-') {
//            string s;
//            cin >> s;
//
//            int x = 0;
//            int p = 1;
//            for(int i = s.length() - 1; i >= 0; i--) {
//                x += (s[i] - '0') % 2 * p;
//                p *= 2;
//            }

            cnt[x] += (c == '+' ? 1 : -1);
        } else {
            cout << cnt[x] << endl;
        }
    }
}