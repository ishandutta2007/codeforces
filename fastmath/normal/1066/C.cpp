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

const int N = 1e6 + 7;
int p[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int l = 0, r = 0;
    int q;
    cin >> q;
    while (q--) {
        char t;
        cin >> t;
        int i; cin >> i;
        if (t == 'L') {
            p[i] = r++;
        }   
        else if (t == 'R') {
            p[i] = l--;
        }   
        else {
            cout << min(p[i] - l, r - p[i]) - 1 << endl;
        }   
        l = min(l, -1ll);
        r = max(r, 1ll);
    }   

}