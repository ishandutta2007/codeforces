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

const int N = 2007;
string a[N];
set <string> ms;

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, k;
    cin >> n >> k;    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ms.insert(a[i]);
    }

    char mem = 'S' ^ 'E' ^ 'T';

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string w;
            for (int t = 0; t < k; ++t) {
                if (a[i][t] == a[j][t]) 
                    w += a[i][t];
                else
                    w += a[i][t] ^ a[j][t] ^ mem;
            }
            ans += ms.find(w) != ms.end();    
        }   
    }   
    cout << ans / 3 << '\n';
}