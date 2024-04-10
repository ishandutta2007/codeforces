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

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;

        int sum = 0;
        int ans;
        for (int i = 1; ; ++i) {
            sum += to_string(i).size();
            if (k <= sum) {
                for (int j = 1; ; ++j) {
                    string t = to_string(j);
                    if (k <= t.size()) {
                        ans = t[k - 1] - '0';
                        break;
                    }   
                    k -= t.size();
                }   
                break;
            }   
            else {
                k -= sum;
            }   
        }   

        cout << ans << endl;
    }   

}