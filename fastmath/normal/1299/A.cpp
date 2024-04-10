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
const int N = 1e5 + 7;
int pref[N], post[N], a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i + 1] = pref[i] | a[i];
    }
    for (int i = n - 1; i >= 0; --i)
        post[i] = post[i + 1] | a[i];
    int ans = -1, p = -1;
    for (int i = 0; i < n; ++i) {
        int nn = a[i] - (a[i] & (pref[i] | post[i + 1]));
        if (nn > ans) {
            ans = nn;
            p = i;
        }   
    }
    swap(a[0], a[p]);
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}