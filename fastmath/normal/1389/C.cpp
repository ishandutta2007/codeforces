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
        string s;
        cin >> s;

        const int C = 10;
        vector <int> cnt(C);
        for (char c : s)
            ++cnt[c - '0'];

        int ans = 0;
        for (int i = 0; i < C; ++i)
            ans = max(ans, cnt[i]);


        for (int a = '0'; a <= '9'; ++a)
            for (int b = '0'; b <= '9'; ++b) {
                int nn = 0;
                for (char c : s) {
                    if ((nn & 1) == 0) {
                        if (c == a)
                            ++nn;
                    }   
                    else {
                        if (c == b)
                            ++nn; 
                    }   
                }   
                if (nn & 1)
                    --nn;
                ans = max(ans, nn);
            }   

        cout << (int)s.size() - ans << endl;
    }   

}