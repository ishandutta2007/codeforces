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

const int N = 1e5 + 7, INF = 5e18;
int n, k;
int a[N];

int f(int a, int x) {
    return x * (a - x * x);
}   
int der(int a, int x) { 
    /*
    int ans = f(a, x + 1) - f(a, x);
    if (ans != a - 3 * x * x - 3 * x - 1) {
        cout << "LMAO" << endl;
        exit(0);
    }   
    return ans;
    */
    return a - 3 * x * x - 3 * x - 1;
}

vector <int> get(int w) {
    vector <int> ans(n);
    for (int i = 0; i < n; ++i) {
        int l = 0;
        int r = a[i] + 1;
        while (l < r - 1) {
            int m = (l + r) >> 1;
            if (der(a[i], m - 1) >= w)
                l = m;
            else
                r = m;
        }   
        ans[i] = l;
    }   
    return ans;
}

int sum(vector <int> a) {
    int ans = 0;
    for (int e : a)
        ans += e;
    return ans;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = -INF, r = INF;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (sum(get(m)) >= k)
            l = m;
        else
            r = m;
    }   
    vector <int> ans = get(r);
    vector <int> add = get(l);
    int want = k;
    for (int e : ans)
        want -= e;
    for (int i = 0; i < n; ++i) {
        int x = min(want, add[i] - ans[i]);
        want -= x;
        ans[i] += x;
    }   
    for (int i = 0; i < n; ++i) 
        cout << ans[i] << ' ';
    cout << endl;
}