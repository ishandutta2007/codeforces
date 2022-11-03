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

/*
1
228 21 11 3
*/

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int c1 = 0, c0 = 0;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == '1' && s[i + 1] == '1')
            c1++;
        else if(s[i] == '0' && s[i + 1] == '0')
            c0++;
    }

    cout << max(c0, c1) << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}