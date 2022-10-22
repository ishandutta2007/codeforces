#include <bits/stdc++.h>

using namespace std;

vector <string> name;

void precalc() {
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            string s;
            s += (char)('A' + i);
            s += (char)('a' + j);
            name.push_back(s);            
        }
    }
}

const int MAXN = 51;

int n, k;
bool ch[MAXN];
void read() {
    cin >> n >> k;
    for (int i = k - 1; i < n; ++i) {
        string s;
        cin >> s;
        ch[i] = (s == "YES");
    }
}

string ans[MAXN];

int u = 0;
string get() {
    return name[u++];
}   

void solve() {
    for (int i = 0; i < k - 1; ++i) ans[i] = get();
    for (int i = k - 1; i < n; ++i) {
        if (ch[i]) ans[i] = get();
        else ans[i] = ans[i - k + 1];
    }
}

void print() {
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();
    read();
    solve();
    print();

    return 0;
}