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
    string s;
    cin >> s;
    int n = s.size();
    struct Dat {
        int len;
        string ans;
        bool want_f;
        void add(char c) {
            want_f = len && (c < ans[0] || (c == ans[0] && want_f));
            len++;
            ans.insert(ans.begin(), c);
            if (len > 11) {
                ans.erase(ans.begin()+5);
            }   
            else if (len == 11) {
                ans = ans.substr(0, 5) + "..." + ans.substr(9, 2);
            }   
        }   
    };  
    vector <Dat> ans(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        if (i + 1 < n && s[i] == s[i + 1] && !(ans[i + 2].ans.size() && (s[i] < ans[i + 2].ans[0] || (s[i] == ans[i + 2].ans[0] && ans[i + 2].want_f)))) {
            //delete i, i + 1
            ans[i] = ans[i + 2];
        }   
        else {
            ans[i] = ans[i + 1];
            ans[i].add(s[i]);
        }   
    }   
    for (int i = 0; i < n; ++i) {
        cout << ans[i].len << ' ' << ans[i].ans << endl;
    }   
}