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

const int N = 2007;
int n, p;
int a[N];
int f(int x) {
    int ans = 1;
    int r = 0;
    for (int i = n - 1; i >= 0; --i) {
        int suff = max(0ll, a[i] - x);
        int can = max(0ll, n - suff);

        ans *= can - r;
        ans %= p;
        
        ++r;
    }   
    return ans;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    cin >> n >> p;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    
    vector <int> ans;
    for (int x = 1; x <= 2000; ++x) {
        if (f(x) % p) {
            ans.app(x);
        }   
    }   
    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e << ' ';
    cout << endl;
}