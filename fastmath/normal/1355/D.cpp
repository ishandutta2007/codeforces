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

    int n, S;
    cin >> n >> S;
    if (S - n + 1 <= n) {
        cout << "NO" << endl;
    }   
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n - 1; ++i)
            cout << 1 << ' ';
        cout << S - n + 1 << endl;
        cout << n << endl;
    }   

}