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
    int k;
    cin >> k;

    string s = "codeforces";

    for (int ans = 1; ; ++ans) {

        vector <int> cnt(10);
        for (int i = 0; i < 10; ++i)
            cnt[i] = ans/10;
        for (int i = 0; i < (ans%10); ++i)
            cnt[i]++;
        
        int f = 1;
        for (int i = 0; i < 10; ++i)
            f *= cnt[i];

        if (f >= k) {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < cnt[i]; ++j)
                    cout << s[i];
            }   
            cout << endl;
            exit(0);
        }   
    }   
    

}