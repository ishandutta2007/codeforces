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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cur += a[i] * a[i];
    }   
    k -= n;

    const int INF = 1e12+7;
    sort(all(a));

    auto f = [&] (int x, int k) {
        assert(1 <= k && k <= x);
        int d = x/k;
        int add = x % k;
        return add * (d + 1) * (d + 1) + (k - add) * d * d;
    };  

    auto get = [&] (int want) {
        int ptr = 1;
        int ans = 0;
        for (auto x : a) {
            while (ptr + 1 <= x && f(x, ptr) - f(x, ptr + 1) >= want) 
                ptr++;
            ans += ptr - 1;
        }   
        return ans;
    };  

    auto sum = [&] (int want) {
        int ptr = 1;
        int ans = 0;
        for (auto x : a) {
            while (ptr + 1 <= x && f(x, ptr) - f(x, ptr + 1) >= want) 
                ptr++;
            ans += f(x, 1) - f(x, ptr);
        }   
        return ans;
    };  

    int l = 0;
    int r = INF;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (get(m) >= k) {
            l = m;                
        }   
        else {
            r = m;
        }   
    }   
    cout << cur - sum(r) - (k - get(r)) * l << endl;

    #ifdef HOME
    cout << Time << endl;
    #endif
}