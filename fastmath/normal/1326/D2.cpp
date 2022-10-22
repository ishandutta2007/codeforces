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

const int N = 2e6 + 7;
int d[N];

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
        string t = "#";
        for (char c : s) {
            t += c;
            t += "#";
        }   

        int r = -1, l = 0;
        for (int i = 0; i < t.size(); ++i) {
            d[i] = 0;
            if (i <= r) 
                d[i] = min(r - i, d[r - i + l]);
            while (i + d[i] + 1 < t.size() && i - d[i] - 1 >= 0 && t[i + d[i] + 1] == t[i - d[i] - 1])
                ++d[i];
            if (i + d[i] > r) {
                l = i - d[i];
                r = i + d[i];
            }   
        }   

        int lcp = 0;
        while (lcp < s.size() && s[lcp] == s[(int)s.size() - lcp - 1])
            ++lcp;

        int mx = -1, pref = 0, post = 0;
        for (int i = 0; i < t.size(); ++i) {
            int l, r;
            if (t[i] == '#') {
                int p = i / 2;
                int rad = (d[i] + 1) / 2;
                l = p - rad;
                r = p + rad - 1;
            }
            else {
                int p = i / 2;
                int rad = d[i] / 2;
                l = p - rad;
                r = p + rad;
            }   
            int pref1 = l;
            int post1 = (int)s.size() - r - 1;
            if (lcp >= pref1 || lcp >= post1) {
                int mx1 = min(pref1, post1) * 2 + (r - l + 1);
                if (mx1 > mx) {
                    mx = mx1;
                    if (pref1 <= post1) {
                        pref = min(pref1, post1) + (r - l + 1);
                        post = min(pref1, post1);
                    }   
                    else {
                        pref = min(pref1, post1);
                        post = min(pref1, post1) + (r - l + 1);
                    }   
                }
            }   
        }   
        cout << s.substr(0, pref) << s.substr((int)s.size() - post, post) << endl;
    }   
}