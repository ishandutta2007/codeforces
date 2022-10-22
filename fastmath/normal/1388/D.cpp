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

const int N = 2e5+7;
int a[N], b[N], dp[N];

vector <int> ans;
vector <int> tree[N];
void calc(int u) {
    dp[u] = a[u];
    for (int v : tree[u]) {
        calc(v);
        if (dp[v] > 0)
            dp[u] += dp[v];
    }   
}   
void print(int u) {
    for (int v : tree[u]) {
        if (dp[v] > 0) {
            print(v);
        }   
    }   
    ans.app(u);
    for (int v : tree[u])
        if (dp[v] <= 0) {
            print(v);
        }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector <int> ro;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        if (b[i] == -1)
            ro.app(i);
        else
            tree[b[i]].app(i);
    }   
    
    for (int u : ro)
        calc(u);
    for (int u : ro)
        print(u);

    int x = 0;
    for (int i : ans) {
        x += a[i];
        if (b[i] != -1)
            a[b[i]] += a[i];
    }   
    cout << x << endl;
    for (int i : ans)
        cout << i << ' ';
    cout << endl;
}