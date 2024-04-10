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
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;

        if (n1 == 0) {
            if (n2 == 0) {
                for (int i = 0; i <= n0; ++i)
                    cout << '0';
            }
            else {
                for (int i = 0; i <= n2; ++i)
                    cout << '1';
            }
            cout << endl;
            continue;                            
        }   

        vector <int> cnt(n1 + 1);
        vector <bool> who;

        vector <int> want(2);
        want[0] = n0;
        want[1] = n2;

        for (int i = 0; i <= n1; ++i)
            who.app(i & 1);
        for (int i = 0; i <= n1; ++i) {
            cout << who[i];
            for (int j = 0; j < want[who[i]]; ++j)
                cout << who[i];
            want[who[i]] = 0;            
        }   
        cout << endl;
    }   
}