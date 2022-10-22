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
#define debug(x) std::cout << #x << ": " << x << '\n';
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    priority_queue <int> q;
    for (int i = 0; i <= k; ++i)
        q.push(0);
    sort(all(c));
    reverse(all(c));
    int ans = 0;
    for (auto x : c) {
        int sum = q.top(); q.pop();
        ans += sum;
        sum += x;
        q.push(sum);                    
    }
    cout << ans << endl;
}