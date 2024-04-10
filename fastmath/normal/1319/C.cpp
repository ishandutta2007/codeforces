#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define f first
#define s second
#define bp __builtin_popcount
#define all(a) a.begin(),a.end()
#define ll long long
#define mp make_pair
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int c = 'z'; c >= 'b'; --c) {
        bool did = 1;
        while (did) {
            did = 0;
            string t;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == c && i && s[i - 1] == s[i] - 1) {
                    ++ans;
                    did = 1;
                }
                else if (s[i] == c && i + 1 < s.size() && s[i + 1] == s[i] - 1) {
                    ++ans;
                    did = 1;
                }
                else
                    t += s[i];
            }   
            s = t;
        }
    }
    cout << ans << endl;
}