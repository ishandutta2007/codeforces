#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t << 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, int> PL;

const int maxn = 2e5 + 5;
const int mod = 998244353;

int a[maxn], b[maxn], op[maxn], vis[maxn];
P seg[maxn];
LL sa[maxn], sb[maxn];
vector<int> L[maxn], R[maxn];
set<int> dl, dr;
queue<P> q;

void handle(int l, int r)
{
    vis[l]++;
    vis[r + 1]--;

    auto it = dl.lower_bound(l);
    vector<int> hd;
    while (it != dl.end() && (*it) <= r)
    {
        hd.push_back(*it);
        q.push(P(*it, 0));
        it++;
    }
    for (auto e:hd) dl.erase(e);
    hd.clear();

    auto it2 = dr.lower_bound(l);
    while (it2 != dr.end() && (*it2) <= r)
    {
        hd.push_back(*it2);
        q.push(P(*it2, 1));
        it2++;
    }
    for (auto e:hd) dr.erase(e);
    hd.clear();

    //cout << l << " " << r << endl;
    //cout << dl.size() << " " << dr.size() << endl;
}

void solve()
{
    int n, m, l, r;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) sa[i] = sa[i - 1] + a[i];
    for (int i = 1; i <= n; i++) sb[i] = sb[i - 1] + b[i];

    for (int i = 1; i <= n; i++) L[i].clear();
    for (int i = 1; i <= n; i++) R[i].clear();
    fill(op, op + m, 0);
    fill(vis, vis + n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        seg[i] = P(l, r);
        L[l].push_back(i);
        R[r].push_back(i);
    }

    dl.clear();
    dr.clear();
    for (int i = 1; i <= n; i++)
    {
        dl.insert(i);
        dr.insert(i);
    }

    int pre = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sa[i] == sb[i])
        {
            q.push(P(pre + 1, 0));
            q.push(P(i, 1));
            dl.erase(pre + 1);
            dr.erase(i);
            pre = i;
        }
    }

    while (!q.empty())
    {
        P e = q.front();
        q.pop();

        if (e.se == 0)
        {
            for (auto r:L[e.fi])
            {
                if (++op[r] == 2) handle(seg[r].fi, seg[r].se);
            }
        }
        else
        {
            for (auto r:R[e.fi])
            {
                if (++op[r] == 2) handle(seg[r].fi, seg[r].se);
            }
        }
    }

    l = 0;
    for (int i = 1; i <= n; i++)
    {
        l += vis[i];
        if (l > 0 || a[i] == b[i]) continue;
        else
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    cin >> pT;
    while (pT--)
    {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}