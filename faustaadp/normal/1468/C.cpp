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

int cnt[mx * 4], maks[mx * 4], apa[mx * 4], kiri[mx * 4];

void upd(int idx, int l, int r, int in, int val, int t)
{
    if (in > r || in < l)
        return;
    if (l == r)
    {
        cnt[idx] += t;
        maks[idx] = val;
        apa[idx] = l;
        kiri[idx] = l;
        return;
    }
    int mid = (l + r) >> 1;

    upd(2 * idx, l, mid, in, val, t);
    upd(2 * idx + 1, mid + 1, r, in, val, t);

    cnt[idx] = cnt[idx * 2] + cnt[idx * 2 + 1];
    maks[idx] = max(maks[idx * 2], maks[idx * 2 + 1]);
    if (maks[idx] == maks[idx * 2])
        apa[idx] = apa[idx * 2];
    else
        apa[idx] = apa[idx * 2 + 1];

    if (cnt[idx * 2] > 0)
        kiri[idx] = kiri[idx * 2];
    else
        kiri[idx] = kiri[idx * 2 + 1];
}

void solve(int tc)
{
    int q;
    cin >> q;
    int idx = 0;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int m;
            cin >> m;
            idx += 1;
            upd(1, 1, 5e5, idx, m, 1);
        }
        else if (t == 2)
        {
            int di = kiri[1];
            upd(1, 1, 5e5, di, 0, -1);
            cout << di << '\n';
        }

        else
        {
            int di = apa[1];
            upd(1, 1, 5e5, di, 0, -1);
            cout << di << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}