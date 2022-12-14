#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

vector<int> prefix_fun(const string &s) {
    int n = SZ(s);
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int &j = pi[i] = pi[i - 1];
        while (j > 0 && s[j] != s[i]) j = pi[j - 1];
        if (s[j] == s[i]) j++;
    }
    return pi;
}

string solve() {
    string s;
    cin >> s;
    int n = SZ(s);
    if (n <= 2) return "Just a legend";

    auto pi = prefix_fun(s);
    int mid = *max_element(begin(pi) + 1, end(pi) - 1);
    int suf = pi[n - 1];
    while (suf > mid) suf = pi[suf - 1];

    if (suf == 0) return "Just a legend";
    else return s.substr(0, suf);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << solve() << '\n';
}