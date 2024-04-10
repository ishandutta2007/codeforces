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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    for (int i = 0; i + p < n; ++i) {
        if (s[i] == s[i + p] && s[i] != '.')
            continue;
        if (s[i] == '.' && s[i + p] == '.') {
            s[i] = '0';
            s[i + p] = '1';
        }               
        else if (s[i] == '.') {
            if (s[i + p] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }   
        else if (s[i + p] == '.') {
            if (s[i] == '0')
                s[i + p] = '1';
            else
                s[i + p] = '0';
        }   

        for (int j = 0; j < n; ++j)
            if (s[j] == '.')
                s[j] = '1';
        cout << s << endl;
        exit(0);

    }   
    cout << "No" << endl;
}