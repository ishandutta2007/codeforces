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


LL dp[maxn], w[maxn];
void Init()
{
    dp[0]=1;
    for (int i = 1; i <= 40000; i++) {
        string u = to_string(i);
        int m = u.size(), fg=0;
        for (int j = 0; j < m; j++) {
            if (u[j] != u[m-j-1]) fg=1;
        }
        if(fg==0) {
            for (int j=0;j<= 40000;j++) {
                if(j>=i) w[j] = w[j-i];
                else w[j]=0;
                LL x = dp[j];
                dp[j] = (dp[j] + w[j]) % mod;

                w[j]+=x;
                w[j] %= mod;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << dp[n] << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    Init();

    int Pt = 1;
    cin >> Pt;
    while (Pt--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}