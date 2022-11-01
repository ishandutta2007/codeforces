#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 100100

ll n, q;
char s[MN]; string str;

map<int, char> seg;
void solve(int l, int r, int k) {
    vector<int> freq(26);
    auto it = prev(seg.upper_bound(l));
    if (it->first < l) {
        seg[l] = it->second;
        it = seg.find(l);
    }

    auto last = seg.upper_bound(r);
    if (last->first > r + 1) {
        seg[r+1] = prev(last)->second;
        last = prev(last);
    }

    while (it != last) {
        freq[it->second - 'a'] += next(it)->first - it->first;
        
        auto tmp = next(it);
        seg.erase(it);
        it = tmp;
    }

    if (k == 1) for (int c = 0; c < 26; c++) {
        if (!freq[c]) continue;
        seg[l] = char('a' + c);
        l += freq[c];
    }
    if (k == 0) for (int c = 25; c >= 0; c--) {
        if (!freq[c]) continue;
        seg[l] = char('a' + c);
        l += freq[c];
    }
    assert(l == r + 1);
}

int main() {
    scanf("%lld %lld %s", &n, &q, s);
    str = s;
    
    for (int i = 0; i < n; i++)
        if (!i || str[i] != str[i-1])
            seg[i] = str[i];
    seg[n] = 'x';

    for (int i = 0, l, r, k; i < q; i++) {
        scanf("%d %d %d", &l, &r, &k);
        solve(l-1, r-1, k);
    }

    int i = 0; char c = '*';
    for (auto tt : seg) {
        while (tt.first > i) str[i++] = c;
        c = tt.second;
    }

    printf("%s\n", str.c_str());
    return 0;
}