#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int mul(int x,int y) {
    LL z = 1LL * x * y;
    return z - z / mod * mod;
}

int add(int x,int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

int powt(int a, int b) {
    int r = 1;
    while(b) {
        if(b & 1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

vector<int> f;
void init()
{
    f.push_back(0);
    LL x = 0, pre = 0;
    for (; pre <= 1e9;x += 4) {
        pre += x;
        f.push_back(pre);
        pre += x + 2;
        f.push_back(pre);
        pre += x + 4;
        f.push_back(pre);
    }
    //cout<<f.size()<<endl;
}

void solve()
{
    int n;
    cin >> n;
    int l = 1, r = f.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (f[mid] < n) l = mid + 1;
        else r = mid;
    }
    cout << l << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    int pT = 1;
    cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}