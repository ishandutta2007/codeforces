#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 7;
int p[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    string s;
    cin >> s;

    int n = s.size();

    p[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] >= s[p[i + 1]]) {
            p[i] = i;
        }   
        else {
            p[i] = p[i + 1];
        }   
    }   

    string ans;
    int i = 0;
    while (i < n) {
        ans += s[p[i]];
        i = p[i] + 1;
    }   

    cout << ans << '\n';
}