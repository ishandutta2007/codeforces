#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 29;

string action[22];
int n, m, team[22], heroes[111], f[22][1 << 20];
bool done[22][1 << 20];
vector <int> bits[1 << 20];

int dp(int i, int mask)
{
    if (i == m) return 0;
    
    int &res = f[i][mask];
    if (done[i][mask]) return res;
    res = -oo;
    done[i][mask] = 1;
    
    if (action[i] == "p")
    {
        int x = bits[mask][0];
        int u = dp(i + 1, mask ^ 1 << x);
        if (team[i] == team[i + 1]) return res = u + heroes[x];
        return res = -u + heroes[x];
    }
    
    for (int j = 0; j < int(bits[mask].size()); j++)
    {
        int x = bits[mask][j], u = dp(i + 1, mask ^ 1 << x);
        if (team[i] == team[i + 1]) res = max(res, u);
        else res = max(res, -u);
    }
    
    return res;
}

int main()
{
    for (int mask = 1; mask < 1 << 20; mask++)
        for (int i = 0; i < 20; i++)
            if (mask >> i & 1)
                bits[mask].push_back(i);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> heroes[i];
    sort(heroes, heroes + n, greater<int>());
    
    cin >> m;
    for (int i = 0; i < m; i++) cin >> action[i] >> team[i];
    
    team[m] = team[m - 1];
    
    int ans = dp(0, (1 << m) - 1);
    if (team[0] == 2) ans = -ans;
    cout << ans << endl;
}