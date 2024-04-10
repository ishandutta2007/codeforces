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
int a[N], t[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    vector <ii> e;
    for (int i = 0; i < n; ++i)
        e.app(mp(a[i], t[i]));
    sort(all(e));
    int x = e[0].f;
    priority_queue <int> q;
    int sum = 0, ptr = 0, ans = 0;
    while (1) {
        while (ptr < e.size() && e[ptr].f == x) {
            q.push(e[ptr].s);
            sum += e[ptr].s;
            ++ptr;
        }   
        sum -= q.top();
        q.pop();
        ans += sum;

        //cout << x << ' ' << sum << ' ' << q.top() << endl;

        if (q.empty()) {
            if (ptr == e.size())
                break;
            x = e[ptr].f;
        }
        else
            ++x;
    }           
    cout << ans << '\n';
}