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
        string s;
        cin >> s;

        vector <int> cnt(2);
        for (char c  : s) {
            ++cnt[c - '0'];
        }   
        int k = min(cnt[0], cnt[1]);
        if (k & 1)
            cout << "DA" << endl;
        else
            cout << "NET" << endl;
    }   

}