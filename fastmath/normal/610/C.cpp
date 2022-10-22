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

const int N = 1001;
bool ans[N][N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int p = 1; p < 10; ++p) {
        int m = 1 << (p - 1);
        for (int i = 0; i < (1 << p); ++i)
            for (int j = 0; j < (1 << p); ++j) 
                ans[i][j] = ans[i % m][j % m] ^ (i >= m && j >= m);
    }
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < (1 << n); ++j)
            if (ans[i][j])
                cout << '*';
            else
                cout << '+';
        cout << endl;
    }
}