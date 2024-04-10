#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;

string a[MAXN];

int cs[MAXN], ch[MAXN];
int per[MAXN];

bool comp(int i, int j) {
    if (ch[i] == 0 && ch[j] == 0) return 0;
    if (ch[i] == 0 && ch[j]) return 1;
    if (ch[j] == 0) return 0;
    if (cs[i] == 0) return 0;
    if (cs[j] == 0 && cs[i]) return 1;
    return ch[i] * cs[j] < ch[j] * cs[i];
}

int get(string &s) {
    int curr = 0;
    int ans = 0;
    for (char c : s) {
        if (c == 's') ++curr;
        else ans += curr;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];      
        for (char c : a[i]) {
            if (c == 's') ++cs[i];
            else ++ch[i];
        }
    }

    for (int i = 0; i < n; ++i) per[i] = i;
    sort(per, per + n, comp);

    string ans;
    for (int i = 0; i < n; ++i) {
        ans += a[per[i]];
    }

    cout << get(ans) << '\n';
    return 0;
}