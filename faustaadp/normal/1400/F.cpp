#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
string s;
ll x, ban = 0;
ll trie[NN][11], fail[NN], sz;
ll d[1100][5100];
ll leaf[NN], n;
ll salah(string s)
{
    ll len = s.length();
    for(ll i = 0; i < len; i++)
    {
        ll jum = 0;
        for(ll j = i; j < len; j++)
        {
            jum += s[j] - '0';
            if(jum > x)
                return 1;
            if(i == 0 && j == len - 1)
                continue;
            if(x % jum == 0)
                return 1;
        }
    }
    return 0;
}
void add(string s)
{
    ll cur = 0;
    for(ll i = 0; i < s.length(); i++)
    {
        ll nx = s[i] - '0';
        if(trie[cur][nx] == -1)
            trie[cur][nx] = ++sz;
        cur = trie[cur][nx];
    }
    // cout << cur << "_\n";
    leaf[cur] = 1;
}
void build()
{
    queue<ll> q;
    fail[0] = 0;
    for(ll i = 0; i < 10; i++)
        if(trie[0][i] == -1)
            trie[0][i] = 0;
        else
        {
            ll nx = trie[0][i];
            fail[nx] = 0;
            q.push(nx);
        }
    while(!q.empty())
    {
        ll now = q.front();
        q.pop();
        for(ll i = 0; i < 10; i++)
            if(trie[now][i] == -1)
                trie[now][i] = trie[fail[now]][i];
            else
            {
                ll nx = trie[now][i];
                fail[nx] = trie[fail[now]][i];
                q.push(nx);
            }
    }
}
void dfs(string s = "", ll sum = 0)
{
    if(salah(s))
    {
        // cout << s << "___\n";
        return ;
    }
    if(sum == x)
    {
        ban++;
        // cout << ban << "\n";
        add(s);
    }
    else
    {
        for(ll i = 1; i <= 9; i++)
            dfs(s + char(i + '0'), sum + i);
    }
}
ll depe(ll pos, ll now)
{
    if(leaf[now])
        return 1e18;
    if(pos == n)
        return 0;
    ll &ret = d[pos][now];
    if(ret == -1)
    {
        ret = min(depe(pos + 1, now) + 1, depe(pos + 1, trie[now][s[pos] - '0']));
        // cout << pos << " " << now  << " " << ret << "\n";
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(trie, -1, sizeof(trie));
    cin >> s;
    cin >> x;
    dfs();
    build();
    // return 0;
    memset(d, -1, sizeof(d));
    n = s.length();
    cout << depe(0, 0) << "\n";
}