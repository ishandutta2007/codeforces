#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct pos
{
    int s, k;
    pos(){}
    pos(int a, int b)
    {
        s = a;
        k = b;
    }
};

inline bool operator < (const pos &a, const pos &b)
{
    return a.s == b.s ? a.k < b.k : a.s < b.s;
}

const int inf = 10000;

int n, m;
string b[2000], s;
int ind[2000];
vector<int> pp[2000][26];
int pp2[2000][26];
pos dp[2001][2001];
int pp3[26];

int main(void)
{
    int i, j;
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> b[i];
    cin >> m;
    for (i = 0; i < m; ++i)
    {
        cin >> ind[i];
        --ind[i];
    }
    cin >> s;
    for (i = 0; i < n; ++i)
        for (j = 0; j < (int)b[i].size(); ++j)
            pp[i][b[i][j] - 'a'].push_back(j);
    for (i = 0; i < 26; ++i)
        pp3[i] = inf;
    for (i = m - 1; i >= 0; --i)
    {
        for (j = 0; j < 26; ++j)
            pp2[i][j] = pp3[j];
        for (j = 0; j < 26; ++j)
            if (pp[ind[i]][j].size())
                pp3[j] = i;
    }
    dp[0][0] = pos(0, -1);
    for (i = 0; i < (int)s.length(); ++i)
    {
        int si = s[i] - 'a';
        for (j = 0; j <= i + 1; ++j)
            dp[i + 1][j] = pos(inf, -1);
        for (j = 0; j <= i; ++j)
            if (dp[i][j].s != inf)
            {
                if (dp[i][j] < dp[i + 1][j])
                    dp[i + 1][j] = dp[i][j];
                pos t = dp[i][j];
                vector<int>::iterator it = upper_bound(pp[ind[t.s]][si].begin(), pp[ind[t.s]][si].end(), t.k);
                if (it == pp[ind[t.s]][si].end())
                {
                    t.s = pp2[t.s][si];
                    if (t.s == inf)
                        t.k = -1;
                    else
                        t.k = pp[ind[t.s]][si][0];
                }
                else
                    t.k = *it;
                if (t < dp[i + 1][j + 1])
                    dp[i + 1][j + 1] = t;
            }
    }
    int ans = 0;
    for (i = 1; i <= (int)s.length(); ++i)
        if (dp[s.length()][i].s != inf)
            ans = i;
    cout << ans;
    return 0;
}