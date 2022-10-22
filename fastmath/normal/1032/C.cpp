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

const int N = 1e5 + 7;
bool dp[N][10];
int par[N][10];
int a[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    for (int i = 0; i < 5; ++i)
        dp[1][i] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (dp[i][j]) {
                for (int k = 0; k < 5; ++k) {
                    if (a[i - 1] < a[i] && j >= k)
                        continue;
                    if (a[i - 1] > a[i] && j <= k)
                        continue;
                    if (a[i - 1] == a[i] && j == k)
                        continue;
                    dp[i + 1][k] = 1;
                    par[i + 1][k] = j;
                }   
            }   
        }   
    }   

    int r = -1;
    for (int i = 0; i < 5; ++i) {
        if (dp[n][i])
            r = i;
    }   
    if (r == -1) {
        cout << "-1" << endl;
    }   
    else {
        vector <int> ans;
        for (int i = n; i; --i) {
            ans.app(r);
            r = par[i][r];
        }
        reverse(all(ans));
        for (int e : ans)
            cout << e + 1 << ' ';
        cout << endl;
    }   
}