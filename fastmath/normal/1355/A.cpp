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

int mindigit(int n) {
    string s = to_string(n);
    int ans = 10;
    for (char c : s) {
        ans = min(ans, (int)(c - '0'));
    }   
    return ans;
}   

int maxdigit(int n) {
    string s = to_string(n);
    int ans = 0;
    for (char c : s) {
        ans = max(ans, (int)(c - '0'));
    }   
    return ans;
}   

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
        int a, k;
        cin >> a >> k;

        --k;
        for (int i = 0; i < k; ++i) {
            if (maxdigit(a) * mindigit(a) == 0)
                break;
            a += maxdigit(a) * mindigit(a);
        }   
        cout << a << endl;
    }   

}