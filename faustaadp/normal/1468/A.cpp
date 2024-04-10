#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a, b) memset(a, b, sizeof a);
#define ALL(x) x.begin(), x.end()

template <typename T>
void cetak(T t)
{
    cout << t << ')' << endl;
}
template <typename T, typename... V>
void cetak(T t, V... v)
{
    cout << t;
    if (sizeof...(v))
        cout << ", ";
    cetak(v...);
}

#define debug(x...)               \
    cout << '(' << #x << ") = ("; \
    cetak(x)
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
typedef int (*func)(int, int);

const int mx = 5e5 + 10;

int maks[mx * 80], L[mx * 80], R[mx * 80];
int idx;

void upd(int pre, int now, int l, int r, int in, int val)
{
    if (l == r)
    {
        maks[now] = max(maks[pre], val);
        return;
    }
    int mid = (l + r) >> 1;
    L[now] = L[pre];
    R[now] = R[pre];
    if (in <= mid)
    {
        L[now] = ++idx;
        upd(L[pre], L[now], l, mid, in, val);
    }
    else
    {
        R[now] = ++idx;
        upd(R[pre], R[now], mid + 1, r, in, val);
    }
    maks[now] = max(maks[L[now]], maks[R[now]]);
}

int cari(int idx, int l, int r, int fl, int fr)
{
    if (fl > r || fr < l)
        return 0;
    if (fl <= l && r <= fr)
    {
        return maks[idx];
    }
    int mid = (l + r) >> 1;

    auto aa = cari(L[idx], l, mid, fl, fr);
    auto bb = cari(R[idx], mid + 1, r, fl, fr);
    return max(aa, bb);
}

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> a(n), root(n + 1);
    root[n] = 0;
    for (int &i : a)
        cin >> i;
    vector<int> b(n);
    iota(ALL(b), 0);
    sort(ALL(b), [&](int i, int j) {
        if (a[i] == a[j])
            return i > j;
        return a[i] > a[j];
    });
    set<int> ini;
    vector<int> kanan(n, n);
    for (int i : b)
    {
        ini.insert(i);
        auto it = ini.upper_bound(i);
        if (it == ini.end())
            continue;
        kanan[i] = *it;
    }
    int ans = 0;
    auto bb = a;
    sort(ALL(bb));
    int tadi = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        root[i] = ++idx;
        int id = lower_bound(ALL(bb), a[i]) - bb.begin();
        upd(tadi, root[i], 0, n - 1, id, 1);
        if (i == n - 1)
        {
            ans = max(ans, 1);
            upd(tadi, root[i], 0, n - 1, id, 1);
            // debug(i, 1);
        }
        else if (kanan[i] == n)
        {
            int x = cari(tadi, 0, n - 1, 0, n - 1) + 1;
            ans = max(ans, x);
            // debug(i, x);
        }
        else
        {
            int x = cari(root[kanan[i] + 1], 0, n - 1, id, n - 1) + 2;
            x = max(cari(tadi, 0, n - 1, id, n - 1) + 1, x);
            ans = max(ans, x);
            // debug(i, x, kanan[i] + 1);
            int apa = x;
            x = cari(tadi, 0, n - 1, 0, n - 1) + 1;
            ans = max(ans, x);
            // debug(i, x);
            upd(tadi, root[i], 0, n - 1, id, apa);
        }
        tadi = root[i];
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}