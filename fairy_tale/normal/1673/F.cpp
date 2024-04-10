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

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int f[]= {0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0};
int a[33][33];

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i= 0; i < n; i++) {
        if (i>0) a[i][0] = a[i-1][0] ^ (1 << (f[i-1] * 2 + 1));
        for (int j = 1; j < n; j++) a[i][j] = a[i][j-1] ^ (1 << (f[j-1] * 2));
    }

    LL tot = 0;
    for (int i= 0; i < n; i++) {
        for (int j = 1; j < n; j++) tot+= (a[i][j] ^ a[i][j - 1]);
        for (int j = 1; j < n; j++) cout << (a[i][j] ^ a[i][j - 1])<< " ";
        cout << endl;
    }

    for (int j = 1; j < n; j++) {
        for (int i= 0; i < n; i++) tot+= (a[j][i] ^ a[j - 1][i]);
        for (int i= 0; i < n; i++) cout << (a[j][i] ^ a[j - 1][i])<< " ";
        cout << endl;
    }
    cout.flush();

    int x, pre = 0;
    while (k--) {
        cin >> x;
        pre ^= x;
        for (int i= 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if(pre==a[i][j]) cout<<i+1<<" "<<j+1<<endl;
        }
        cout.flush();
    }

    //cout<<tot<<endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Pt = 1;
    //cin >> Pt;
    while (Pt--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}