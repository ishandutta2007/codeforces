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

        int dif = 0;
        for (int i = 1; i < s.size(); ++i)
            dif += s[i] != s[i-1];

        if (dif == 0) {
            cout << s << endl;
        }   
        else {
            int ptr = 0;
            while (s[ptr] == '0') {
                cout << '0';
                ++ptr;
            }
            if (dif > 1 || !(s[0] == '0' && s.back()=='1')) {
                cout << '0';
            }
            ptr = n - 1;
            while (s[ptr] == '1') {
                cout << '1';
                --ptr;
            }   
            cout << endl;
        }   
    }   
}