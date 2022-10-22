#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {

        int l, r, m;
        cin >> l >> r >> m;

        int tl = m - (r - l);
        int tr = m + (r - l);

        for (int a = l; a <= r; ++a) {

            if (tr/a > (tl - 1)/a) {
                int x = tr/a * a;
                int de = m - x;
                for (int b = l; b <= r; ++b) {
                    int c = b - de;
                    if (l <= c && c <= r) {
                        cout << a << ' ' << b << ' ' << c << endl;
                        break;
                    }   
                }       
                break;

            }   
        
        }   
        
    }   
}