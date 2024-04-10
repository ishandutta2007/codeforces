#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2e5 + 7;
int n, k;
int l[N], r[N], a[N];
set <ii> ms;
void del(int i) {
    ms.erase(mp(a[i], i));
    int tl = l[i];
    int tr = r[i];
    if (tl != -1)
        r[tl] = tr;
    if (tr != n)
        l[tr] = tl;
}   
bool ans[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ms.insert(mp(a[i], i));
    }   
    for (int i = 0; i < n; ++i) {
        l[i] = i-1;
        r[i] = i+1;
    }
    bool t = 0;
    while (ms.size()) {
        int i = ms.rbegin()->s;
        ms.erase(*ms.rbegin());        

        vector <int> mem = {i};
        int cur = i;
        for (int j = 0; j < k; ++j) {
            cur = l[cur];
            if (cur == -1)
                break;
            mem.app(cur);
        }   
        cur = i;
        for (int j = 0; j < k; ++j) {
            cur = r[cur];
            if (cur == n)
                break;
            mem.app(cur);
        }   
        for (int i : mem)
            del(i);
        for (int i : mem)
            ans[i] = t;
        t ^= 1;
    }   
    for (int i = 0; i < n; ++i)
        cout << ans[i] + 1;
    cout << '\n';
}