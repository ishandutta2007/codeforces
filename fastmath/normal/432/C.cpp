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
const int N = 1e5 + 2007;
bool p[N];
ii sum[N];
vector <int> get2(int n) {
    vector <int> ans = {sum[n].f, sum[n].s};
    return ans;
}   
vector <int> get3(int n) {
    vector <int> ans;
    if (n & 1) {
        ans = get2(n - 3);
        ans.app(3);
    }   
    else {
        ans = get2(n - 2);
        ans.app(2);
    }   
    return ans;
}   

vector <ii> ans;
void kek(int i, int j, vector <int> &a, vector <int> &pos) {
    swap(a[i], a[j]);
    swap(pos[a[i]], pos[a[j]]);
    ans.app(mp(min(i, j), max(i, j)));        
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 2; i < N; ++i)
        p[i] = 1;
    vector <int> v;
    for (int i = 2; i < N; ++i) {
        if (p[i]) {
            v.app(i);
            for (int j = 2 * i; j < N; j += i)
                p[j] = 0;
        }   
    }   
    for (int a : v) {
        for (int b : v) {
            if (a + b < N)
                sum[a + b] = mp(a, b);
        }   
    }   
    int n;
    cin >> n;
    vector <int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }   
    for (int i = 1; i <= n; ++i) {
        if (pos[i] == i)
            continue;
        if (p[pos[i] - i + 1]) {
            kek(i, pos[i], a, pos);
        }   
        else if (sum[pos[i] - i + 2].f) {
            int w = pos[i] - i + 2;
            vector <int> mem = get2(w);
            int cur = pos[i];
            for (int len : mem) {
                kek(cur - len + 1, cur, a, pos);
                cur = cur - len + 1;
            }   
        }   
        else {
            int w = pos[i] - i + 3;
            vector <int> mem = get3(w);
            int cur = pos[i];
            for (int len : mem) {
                kek(cur - len + 1, cur, a, pos);
                cur = cur - len + 1;
            }   
        }   
    }   
    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e.f << ' ' << e.s << endl;
}