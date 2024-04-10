#include <iostream>
#include <fstream>
#include <algorithm>
#define ll long long
using namespace std;

int n;
ll a[100005],pref[100005],suff[100005];
ll ans;

struct node {
    int trie0,trie1;
} e[31001005];

int ei = 1;

ll query(ll num) {
    ll res = 0;
    int curidx = 0;
    for (ll i = 63; i >= 0 && curidx >= 0; --i) {
        res <<= 1ll;
        if ((num >> i) & 1ll) {
            if (e[curidx].trie1 == -1) {
                curidx = e[curidx].trie0;
            } else {
                curidx = e[curidx].trie1;
                res |= 1ll;
            }
        } else {
            if (e[curidx].trie0 == -1) {
                curidx = e[curidx].trie1;
                res |= 1ll;
            } else {
                curidx = e[curidx].trie0;
            }
        }
    }
    return res;
}

void add(ll num) {
    int curidx = 0;
    for (int i = 63; i >= 0; --i) {
        if ((num >> i) & 1ll) {
            if (e[curidx].trie1 == -1) {
                e[curidx].trie1 = ei;
                ++ei;
            }
            curidx = e[curidx].trie1;
        } else {
            if (e[curidx].trie0 == -1) {
                e[curidx].trie0 = ei;
                ++ei;
            }
            curidx = e[curidx].trie0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 31001005; ++i)
        e[i].trie0 = e[i].trie1 = -1;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        pref[i] = a[i] ^ pref[i-1];
        ans = max(ans,pref[i]);
    }
    for (int i = n; i >= 1; --i) {
        suff[i] = a[i] ^ suff[i+1];
        ans = max(ans,suff[i]);
    }
    add(0ll);
    for (int i = n; i >= 1; --i) {
        ll getm = query(~pref[i]);
        ans = max(ans, getm ^ pref[i]);
        add(suff[i]);
    }
    ans = max(ans, query(~0ll));
    cout << ans;
    return 0;
}