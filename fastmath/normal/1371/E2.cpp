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

const int N = 1e5+7;
int n, p;
int a[N];
bool check(int x) {
    int ans = 1;
    int r = 0;
    for (int i = n - 1; i >= 0; --i) {
        int can = min(n, n - a[i] + x);

        if (can <= r)
            return 0;

        ans *= can - r;
        ans %= p;
        
        ++r;
    }   
    return 1;
}   

int mod(int n) {
    n %= p;
    if (n < 0)
        return n + p;
    else
        return n;
}   

int f[N];

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

    int COR = -1;
    {
    int l = 0;
    int r = 1e9+7;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (check(m))
            r = m;
        else
            l = m;
    }
    COR = r;   
    }

    const int INF = 1e18;
    int UP = INF;
    for (int i = 0; i < N; ++i)
        f[i] = COR;

    {
    int r = 0;
    for (int i = n - 1; i >= 0; --i) {
        //int f = n - a[i] - r; //+x

        //n - a[i] - r + x = 0 mod p
        int ban = mod(-mod(n-a[i]-r));        
        f[ban] = max(f[ban], a[i]);


        //min(n, n - a[i] + x);
        //n - a[i] + x >= n
        //x >= a[i]
        if ((n - r) % p == 0) {
            UP = min(UP, a[i]);
        }   

        ++r;
    }
    }   

    if (UP == INF) {
        exit(1);
    }   

    #ifdef HOME
    debug(COR);
    debug(UP);
    #endif

    vector <int> ans;
    for (int rem = 0; rem < p; ++rem) {
        //x * p + rem >= f[i]
        //x * p >= f[i] - rem

        int x = 0;
        if (f[rem] > rem)
            x = (f[rem] - rem + p - 1) / p;            
        int lf = x * p + rem;
        
        while (lf < UP) {
            ans.app(lf);
            lf += p;
        }   
    }   

    sort(all(ans));

    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e << ' ';
    cout << endl;
}