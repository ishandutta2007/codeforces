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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    reverse(all(a));

    deque <int> ans;
    ans.app(a[0]);
    for (int i = 1; i < n; i += 2) {
        ans.push_front(a[i]);
        if (i + 1 < a.size())
            ans.app(a[i + 1]);            
    }   
    vector <int> ar;
    for (int e : ans)
        ar.app(e);
    for (int i = 0; i < n; ++i) {
        int l = (i - 1 + n) % n;
        int r = (i + 1) % n;
        if (ar[i] >= ar[l] + ar[r]) {
            cout << "NO\n";
            exit(0);
        }   
    }
    cout << "YES\n";
    for (int e : ar)
        cout << e << ' ';
    cout << '\n';
}