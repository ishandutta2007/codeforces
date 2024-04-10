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

bool mem[26];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string good;
    cin >> good;
    string sh;
    cin >> sh;

    for (char c : good) 
        mem[c - 'a'] = 1;

    int p = -1;
    for (int i = 0; i < sh.size(); ++i)
        if (sh[i] == '*')
            p = i;
    string l, r;
    if (p != -1) {
        l = sh.substr(0, p);
        r = sh.substr(p + 1, (int)sh.size() - p - 1);
    }   

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s.size() < sh.size() - 1) {
            cout << "NO\n";
            continue;
        }   
        if (p == -1) {
            if (sh.size() != s.size()) {
                cout << "NO\n";
                continue;
            }   
            string ans = "YES";
            for (int i = 0; i < s.size(); ++i) {
                if (sh[i] == '?') {
                    if (!mem[s[i] - 'a']) {
                        ans = "NO";
                    }   
                }
                else {
                    if (s[i] != sh[i])
                        ans = "NO";
                }   
            }   
            cout << ans << '\n';
        }   
        else {
            string ans = "YES";
            for (int i = 0; i < l.size(); ++i) {
                if (l[i] == '?') {
                    if (!mem[s[i] - 'a']) {
                        ans = "NO";
                    }   
                }
                else {
                    if (s[i] != l[i])
                        ans = "NO";
                }   
            }   
            int add = (int)s.size() - (int)r.size();
            for (int i = 0; i < r.size(); ++i) {
                if (r[i] == '?') {
                    if (!mem[s[add + i] - 'a']) {
                        ans = "NO";
                    }   
                }
                else {
                    if (s[add + i] != r[i])
                        ans = "NO";
                }   
            }   
            for (int i = l.size(); i < add; ++i) {
                if (mem[s[i] - 'a'])
                    ans = "NO";
            }   
            cout << ans << '\n';
        }   
    }   
}