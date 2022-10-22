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
        int n;
        cin >> n;
        string s;
        cin >> s;
    
        string w = "abacaba";

        auto get = [&](string s) {
            int ans = 0;
            for (int i = 0; i + w.size() - 1 < s.size(); ++i)   
                ans += s.substr(i, w.size()) == w;
            return ans;                                
        };  

        string ans;
        for (int i = 0; i + 6 < n; ++i) {
            
            string t = s;
            for (int j = 0; j < i; ++j)
                if (t[j] == '?')
                    t[j] = 'z';
            for (int j = i + 7; j < n; ++j) 
                if (t[j] == '?')
                    t[j] = 'z';
            for (int j = i; j < i + 7; ++j)
                if (t[j] == '?')
                    t[j] = w[j - i];
            if (get(t) == 1) {
                ans = t;
            }                           
            
        }       

        if (ans.empty()) 
            cout << "NO" << endl;
        else
            cout << "YES" << endl << ans << endl;

    }   
}