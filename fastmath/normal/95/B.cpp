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

bool check(string s) {
    int cnt4 = 0, cnt7 = 0;
    for (char c : s)
        if (c == '4')
            ++cnt4;
        else if (c == '7')
            ++cnt7;
    if (cnt4 == cnt7 && cnt4 + cnt7 == s.size())
        return 1;
    else
        return 0;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    string s;
    cin >> s;

    int n = s.size();

    if (check(s)) {
        cout << s << '\n';
        exit(0);
    }   

    if (s.size() % 2 == 1) {
        ++n;
        for (int i = 0; i < n / 2; ++i)
            cout << '4';
        for (int i = 0; i < n / 2; ++i)
            cout << '7';
    }   
    else {
        int cnt4 = 0, cnt7 = 0, r = -1, mem = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '4' && s[i] != '7') {
                if (cnt4 < n / 2 && s[i] < '4') {
                    r = i;
                    mem = 4;
                }   
                else if (cnt7 < n / 2 && s[i] < '7') {
                    r = i;
                    mem = 7;
                }   
                break;
            }   
            else if (s[i] == '4') {
                if (cnt7 < n / 2) {
                    r = i;
                    mem = 7;
                }   
                ++cnt4;
            }   
            else {
                ++cnt7;
            }   
            if (cnt4 > n / 2 || cnt7 > n / 2)
                break;
        }   
        if (r == -1) {
            n += 2;
            for (int i = 0; i < n / 2; ++i)
                cout << '4';
            for (int i = 0; i < n / 2; ++i)
                cout << '7';
            exit(0);
        }   

        int c4 = 0, c7 = 0;
        for (int i = 0; i < r; ++i) {
            if (s[i] == '4')
                ++c4;
            else
                ++c7;
            cout << s[i];
        }   
        cout << mem;
        if (mem == 4)
            ++c4;
        else
            ++c7;
        for (int i = r + 1; i < n; ++i) {
            if (c4 < n / 2) {
                cout << '4';
                ++c4;
            }   
            else 
                cout << '7';
        }
        cout << '\n';        
        exit(0);
    }   
}