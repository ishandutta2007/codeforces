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

vector <int> ans[45];

bool al[45];

bool prime(int n) {
    for (int i = 2; i * i <= n; ++i)    
        if (n % i == 0)
            return 0;
    return 1;
}   

bool check(int n) {
    return al[n];
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int n = 1; n < 45; ++n) {
        for (int p = 2; p < n; ++p) {
            if (n % p == 0) {
                int q = n/p;
                if (p < q && prime(p) && prime(q))
                    al[n] = 1;
            }   
        }   
    }   

    for (int n = 1; n < 45; ++n) {

        for (int a = 1; a <= n; ++a) {
            for (int b = a + 1; a + b <= n; ++b) {
                for (int c = b + 1; a + b + c <= n; ++c) {

                    int d = n - a - b - c;
                    if (d > c) {

                        if (check(a) + check(b) + check(c) + check(d) >= 3) {
                            ans[n] = {a, b, c, d};
                        }   

                    }   

                }   
            }   
        }
        
    }       
    
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;

        if (n >= 45) {
            cout << "YES" << endl;
            cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n - 30 << endl;
            continue;
        }   

        if (ans[n].empty())
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (auto e : ans[n])
                cout << e << ' ';
            cout << endl;
        }   
    }   

}