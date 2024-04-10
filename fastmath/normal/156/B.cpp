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
char t[N];
int a[N], cnt[N][2];
int all[2];
bool can[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> a[i];        
        ++cnt[a[i]][t[i] == '+'];
        ++all[t[i] == '+'];
    }   
    int k = 0;
    for (int i = 1; i <= n; ++i) {
        int f = (all[0] - cnt[i][0]) + cnt[i][1];
        can[i] = f == m;
        k += can[i];
    }   
    for (int i = 1; i <= n; ++i) {
        if (can[a[i]] && k > 1) {
            cout << "Not defined\n";
        }                           
        else if (can[a[i]] == (t[i] == '+')) {
            cout << "Truth\n";
        }   
        else {
            cout << "Lie\n";
        }   
    }   
}