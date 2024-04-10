#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct trie {
    ll val = 0;
    trie* ch[2];

    trie() { ch[0] = ch[1] = NULL;}

    void add(ll seq, int pos = 50) {
        if(pos < 0) return void(val = seq);
        int nxt = ((seq & (1LL << pos)) != 0);
        if(ch[nxt] == NULL) ch[nxt] = new trie();
        ch[nxt]->add(seq, pos - 1);
    }

    ll m(ll x, int pos = 50) {
        if(pos < 0) return x ^ val;
        int nxt = ((x & (1LL << pos)) == 0);
        if(ch[nxt] == NULL) nxt = 1 - nxt;
        assert(ch[nxt]);
        return ch[nxt]->m(x, pos - 1);
    }
} dict;

ll n, a[100010], ans, x, px;

int main() {
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        x ^= a[i];
    }

    dict.add(0);
    for(int i = n-1; i >= 0; i--) {
        ans = max(ans, dict.m(x));
        x ^= a[i];
        px ^= a[i];
        dict.add(px);
    }
    ans = max(ans, dict.m(x));

    printf("%lld\n", ans);
    return 0;
}