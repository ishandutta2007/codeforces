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

    string s;
    cin >> s;

    for (int i = 0; i + 2 < s.size(); ++i) {
        set <char> ms;
        ms.insert(s[i]);
        ms.insert(s[i + 1]);
        ms.insert(s[i + 2]);
        ms.erase('.');
        if (ms.size() == 3) {
            cout << "Yes" << endl;
            exit(0);
        }   
    }
    cout << "No" << endl;
}