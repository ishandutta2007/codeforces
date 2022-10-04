#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int long long

struct kek {
    int pr, sf, ans;
    char cp, cs;
    bool fl;
    vector <int> mx;
    kek() {
        pr = sf = ans = 0;
        fl = 0;
        cp = cs = '?';
        mx.resize(26, 0);
    }
};

kek get(string s) {
    int n = s.size();
    kek res;
    res.cp = s[0];
    res.cs = s[(int)s.size() - 1];
    int uk = 0;
    while (uk < n && s[uk] == res.cp) ++uk;
    res.pr = uk;
    uk = 0;
    while (uk < n && s[n - uk - 1] == res.cs) ++uk;
    res.sf = uk;
    int cnt = 1;
    res.ans = 1;
    res.mx[s[0] - 'a'] = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) ++cnt;
        else cnt = 1;
        res.ans = max(res.ans, cnt);
        res.mx[s[i] - 'a'] = max(res.mx[s[i] - 'a'], cnt);
    }
    if (res.ans == n) res.fl = 1;
    else res.fl = 0;
    return res;
}

kek concat(kek a, kek b, int n) {
    kek res;
    res.fl = (a.fl & b.fl) & (a.cp == b.cp);
    res.cp = b.cp;
    res.cs = b.cs;
    res.pr = b.pr;
    res.sf = b.sf;

    if (b.fl) {
        if (a.cp == b.cp) {
            res.pr = n * (a.pr + 1) + a.pr;
        }
        if (a.cs == b.cs) {
            res.sf = n * (a.sf + 1) + a.sf;
        }
        res.mx[b.cp - 'a'] = n * (a.mx[b.cp - 'a'] + 1) + a.mx[b.cp - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
        res.mx[i] = max(res.mx[i], b.mx[i]);
        if (a.mx[i] > 0) res.mx[i] = max(res.mx[i], 1LL);
    }
    res.mx[b.cp - 'a'] = max(res.mx[b.cp - 'a'], b.pr + min(1LL, a.mx[b.cp - 'a']));
    res.mx[b.cs - 'a'] = max(res.mx[b.cs - 'a'], b.sf + min(1LL, a.mx[b.cs - 'a']));
    if (b.cp == b.cs && a.mx[b.cp - 'a'] > 0) {
        res.mx[b.cs - 'a'] = max(res.mx[b.cs - 'a'], b.pr + b.sf + 1);
    }
    for (int i = 0; i < 26; ++i) res.ans = max(res.ans, res.mx[i]);
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector <string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    kek res = get(a[0]);
    for (int i = 1; i < n; ++i) {
        res = concat(res, get(a[i]), (int)a[i].size()); 
    }  
    cout << res.ans << '\n';
}