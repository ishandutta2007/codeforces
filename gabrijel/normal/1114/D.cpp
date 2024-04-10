#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 5100;
const int inf = 1e9;

int n;
int pn;

vector <int> svi;

int dp[maxn][maxn];

int rek(int l, int r)
{
    if(dp[l][r] != -1) return dp[l][r];
    if(l == r) return dp[l][r] = 0 ;
    int ret = inf;
    if(svi[l] == svi[r]) ret = min(ret, rek(l + 1, r - 1) + 1);
    ret = min(ret, rek(l + 1, r) + 1);
    ret = min(ret, rek(l, r - 1) + 1);
    return dp[l][r] = ret;
}

int main()
{
    memset(dp, -1, sizeof dp);
    cin >> n;
    pn = n;
    int x;
    REP(i, 0, pn)
    {
        scanf("%d", &x);
        if(svi.size() && svi.back() == x)
        {
            n--;
        }
        else
        {
            svi.push_back(x);
        }
    }
    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    int rj = inf;
    if(svi[0] == svi.back()) rj = min(rj, rek(1, n - 2) + 1);
    printf("%d\n", min(rj, min(rek(1, n - 1) + 1, rek(0, n - 2) + 1)));
    return 0;
}