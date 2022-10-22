#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll inf = 1e18 + 7;
void upd(ll& a, const ll& b)
{
    a = min(a + b, inf);
}
const int maxn = 1007, maxm = 1007, abc = 26;
vector<vector<ll> > dp(maxm, vector<ll>(maxn, 0)), add(maxm, vector<ll>(maxn, 0));
vector<vector<int> > son(maxn* maxn, vector<int>(abc, -1));
vector<int> p(maxn* maxn, -1), in(maxn* maxn, -1);
vector<char> pv(maxn* maxn, '?');
int n, m, nodes = 1;
string s;
ll k;
void insert_string(int pos)
{
    for (int vr = 0; pos < n; vr = son[vr][s[pos] - 'a'], pos++)
    {
        if (son[vr][s[pos] - 'a'] == -1)
        {
            son[vr][s[pos] - 'a'] = nodes++;
            in[nodes - 1] = pos;
            p[nodes - 1] = vr;
            pv[nodes - 1] = s[pos];
        }
    }
}
vector<int> ord;
void sort_substrings(int vr)
{
    ord.push_back(vr);
    for (int i = 0; i < abc; i++)
    {
        if (son[vr][i] != -1) sort_substrings(son[vr][i]);
    }
}
ll count_smaller(const string &t)
{
    vector<int> pos(n, -1);
    for (int i = 0; i < n; i++)
    {
        pos[i] = i;
        while (pos[i] < n && pos[i] - i < t.size() && t[pos[i] - i] == s[pos[i]]) pos[i]++;
        if (pos[i] - i < t.size() && (pos[i] == n || s[pos[i]] < t[pos[i] - i])) pos[i] = -1;
        else if (pos[i] - i < t.size()) pos[i]++;
    }
    for (int i = 0; i <= m; i++) for (int j = 0; j <= n; j++) dp[i][j] = add[i][j] = 0;
    dp[0][0] = 1;
    //cout << t << "\n";
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j) upd(add[i][j], add[i][j - 1]);
            upd(dp[i][j], add[i][j]);
            //cout << dp[i][j] << " ";
            if (i < m && j < n && pos[j] != -1) upd(add[i + 1][pos[j]], dp[i][j]);
        }
        //cout << "\n";
    }
    return dp[m][n];
}
string get_string(int vr)
{
    string ans = "";
    while (vr)
    {
        ans.push_back(pv[vr]);
        vr = p[vr];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> s;
    for (int i = 0; i < n; i++) insert_string(i);
    sort_substrings(0);
    int lo = 0, hi = ord.size() - 1;
    while (lo < hi)
    {
        int mid = (lo + hi + 1) >> 1;
        if (count_smaller(get_string(ord[mid])) >= k) lo = mid;
        else hi = mid - 1;
    }
    cout << get_string(ord[lo]) << "\n";
    return 0;
}