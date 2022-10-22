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
int l[N], r[N];
 
int a[N];
 
bool used[N];
 
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
 
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
 
    set <ii> ms;
    for (int i = 0; i < n; ++i) {
        l[i] = i - 1;
        r[i] = i + 1;
    }   
    r[n] = n;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i + 1]) {
            ms.insert(mp(abs(a[i] - a[i + 1]), i));
        }   
    }   
    vector <ii> ans;
    while (ms.size()) {
        int i = ms.begin()->s;
        ms.erase(ms.begin());
        if (used[i] || used[r[i]])
            continue;
        ans.app(mp(i, r[i]));
        used[i] = used[r[i]] = 1;

        int tl = l[i];
        int tr = r[r[i]];
        ms.erase(mp(abs(a[tl] - a[i]), tl));
        ms.erase(mp(abs(a[tr] - a[r[i]]), r[i]));

        if (tl != -1) 
            r[tl] = tr;
        if (tr != n) 
            l[tr] = tl;
        if (tl != -1 && tr != n && s[tl] != s[tr]) {
            ms.insert(mp(abs(a[tl] - a[tr]), tl));
        }   
    }   
    cout << ans.size() << '\n';
    for (auto e : ans)
        cout << e.f + 1 << ' ' << e.s + 1 << '\n';    
 
}