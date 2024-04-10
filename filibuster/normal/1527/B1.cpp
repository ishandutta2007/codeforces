#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 998244353;
const int N = 3013;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += (s[i] == '0');

    if(cnt == 1) {
        cout << "BOB" << endl;
    } else if(cnt % 2 == 0) {
        cout << "BOB" << endl;
    } else {
        cout << "ALICE" << endl;
    }

}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}