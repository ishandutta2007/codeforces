#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxc = 26;
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
void compute_automaton(string s, vector<vector<int>>& aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    for (char c : s) c = 'a' + rand() % 26;
    int n = s.size();
    vector<vector<int>> aut;
    vector<int> pi = prefix_function(s);
    compute_automaton(s, aut);
    vector<int> f(n + 1);
    for (int p = n; p; p = pi[p - 1])
        f[p] = 1;
    int q;
    cin >> q;
    for (int i = 0; i < q; i += 1) {
        string t;
        cin >> t;
        int p = n;
        for (int j = 0; j < t.size(); j += 1) {
            p = aut[p][t[j] - 'a'];
            int ans = p;
            for (int k = j - 1; k >= 0; k -= 1) {
                int ok = 1;
                for (int x = j; x >= 0 and n + k - (j - x) >= 0 and ok; x -= 1) {
                    char c = k - (j - x) >= 0 ? t[k - (j - x)] : s[n + k - (j - x)];
                    if (c != t[x]) ok = 0;
                }
                if (ok and n - (j - k) >= 0) {
                    if (not f[n - (j - k)]) ok = 0;
                }
                if (ok) {
                    ans = n + k + 1;
                    break;
                }
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}