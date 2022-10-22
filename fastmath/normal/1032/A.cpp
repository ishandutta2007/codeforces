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
    int n, k;
    cin >> n >> k;
    map <int, int> d;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++d[x];
    }   
    int cnt = 0;
    for (auto e : d) {  
        cnt = max(cnt, (e.s + k - 1) / k);
    }   
    cout << d.size() * k * cnt - n << '\n';
}