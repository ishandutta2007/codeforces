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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool h1 = 0, h2 = 0;
        for (char c : s) {
            if (c == '<')
                h1 = 1;
            if (c == '>')
                h2 = 1;
        }   

        if (!h1 || !h2) {
            cout << n << endl;
        }   
        else {
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                int l = (i + n - 1) % n;
                if (s[i] == '-' || s[l] == '-')
                    ans++;
            }
            cout << ans << endl;
        }   

    }   
}