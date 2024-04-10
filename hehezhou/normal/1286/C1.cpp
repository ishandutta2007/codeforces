#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull w[26];
struct node {
    int buc[26];
    node() {
        memset(buc, 0, sizeof buc);
    }
    inline int& operator[] (int x) {
        return buc[x];
    }
    inline const int& operator[] (int x) const {
        return buc[x];
    }
    ull hsh() {
        ull ans = 0;
        for (int i = 0; i < 26; i++) ans += buc[i] * w[i];
        return ans;
    }
    friend inline node operator - (const node &a, const node &b) {
        node ans;
        for (int i = 0; i < 26; i++) ans[i] = a[i] - b[i];
        return ans;
    }
    inline int able() {
        for (int i = 0; i < 26; i++) {
            if (buc[i] < 0) return 0;
        }
        return 1;
    }
    inline int find_first() {
        for (int i = 0; i < 26; i++) {
            if (buc[i]) return i;
        }
        return -1;
    }
};
vector < node > a[110], b[110], c[110];
typedef map < ull, int > mui;
string lans, rans;
int main() {
    srand(time(0));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 4; j++) w[i] = w[i] << 16 | rand();
    }
    ios :: sync_with_stdio(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "? 1 1" << endl;
        string x;
        cin >> x;
        cout << "! " << x << endl;
        return 0;
    }
    int mid = n >> 1;
    mid++;
    cout << "? 1 " << n << endl;
    cout << "? 1 " << mid << endl;
    cout << "? 1 " << mid - 1 << endl;
    cout.flush();
    for (int i = 1; i <= n * (n + 1) / 2; i++) {
        string x;
        cin >> x;
        node now;
        for (auto i : x) now[i - 'a']++;
        a[x.size()].push_back(now);
    }
    for (int i = 1; i <= mid * (mid + 1) / 2; i++) {
        string x;
        cin >> x;
        node now;
        for (auto i : x) now[i - 'a']++;
        b[x.size()].push_back(now);
    }
    for (int i = 1; i <= mid * (mid - 1) / 2; i++) {
        string x;
        cin >> x;
        node now;
        for (auto i : x) now[i - 'a']++;
        c[x.size()].push_back(now);
    }
    node last;
    for (int i = 1; i <= mid; i++) {
        mui x;
        for (auto j : b[i]) x[j.hsh()]++;
        for (auto j : c[i]) x[j.hsh()]--;
        node now;
        for (auto j : b[i]) if (x[j.hsh()]) now = j;
        lans = char((now - last).find_first() + 'a') + lans;
        last = now;
    }
    node all = a[n][0];
    int l = mid, r = n, cnt = n;
    last = all;
    while (l < r) {
        cnt--;
        mui m;
        for (int i = 0; i < n - cnt; i++) {
            ull tmp = all.hsh();
            for (int j = 0; j < i; j++) tmp -= w[rans[j] - 'a'];
            for (int j = 0; j < n - cnt - i; j++) tmp -= w[lans[j] - 'a'];
            m[tmp]--;
        }
        for (auto i : a[cnt]) m[i.hsh()]++;
        node x;
        for (auto i : a[cnt]) if (m[i.hsh()]) x = i;
        rans += char('a' + (last - x).find_first());
        last = x;
        r--;
    }
    reverse(rans.begin(), rans.end());
    return cout << "! " << lans + rans << endl, 0;
}