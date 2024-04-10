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
const int N = 5007, INF = 1e8;
int a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 1; i < N; ++i) {
        a[i] = a[i - 1] + (i - 1) / 2;
    }       
    int n, m;
    cin >> n >> m;
    if (m > a[n]) {
        cout << "-1\n";
        exit(0);
    }   
    int p = 0;
    while (a[p + 1] <= m && p + 1 <= n) 
        ++p;
    vector <int> ans;
    for (int i = 1; i <= p; ++i)
        ans.app(i);
    int w = m - a[p];
    if (w) 
        ans.app(2 * p - 2 * w + 1);
    int ptr = INF;
    while (ans.size() < n) {
        ans.app(ptr);
        ptr += N;
    }   
    for (int e : ans)
        cout << e << ' ';
    cout << '\n';
}