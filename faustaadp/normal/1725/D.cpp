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

const int mx = 1e5 + 10;
const int MOD = 1e9 + 7;

long long op(long long x, long long c)
{
    x -= 1LL << c;
    x *= 2;
    return x;
}

set<long long> sudah;

set<long long> bisa(long long x)
{
    set<long long> ret;
    int c = 0;
    while (x > 0)
    {
        ret.insert(x);
        x = op(x, c);
        c += 1;
    }
    return ret;
}

void solve(int tc)
{
    long long n, q;
    // cin >> n >> q;
    // long long ans = n * (n + 1) / 2;
    // debug(ans);
    // map<long long, long long> aa;
    // for (int i = 1; 1; i++)
    // {
    //     long long jadi = 1LL << (i - 1);
    //     if (jadi <= n)
    //     {
    //         debug(i, jadi);
    //         ans -= jadi - i;
    //         aa[jadi] = i;
    //     }
    //     else
    //         break;
    // }
    // cout << ans << '\n';
    cin >> q;
    for (long long x = 1; x <= q; x++)
    {
        // long long x;
        // cin >> x;
        auto xx = bisa(x);
        cout << x << endl;
        for (auto i : xx)
        {
            if (sudah.count(i))
            {
                cout << " x";
            }
            else
                cout << ' ' << i;
            sudah.insert(i);
        }
        cout << endl;
        // if (aa.count(x))
        // {
        //     cout << aa[x] << '\n';
        // }
        // else
        //     cout << x << '\n';
    }
}

map<long long, long long> batas;

long long solve2(int tc)
{
    long long n, q;
    cin >> n >> q;
    long long sisa = n;
    int sampai;
    long long mini = 0;
    for (int i = 1; i < mx; i++)
    {
        int x = (i + 1) / 2;
        if (x >= sisa)
        {
            sampai = i;
            mini += 1LL * sisa * i;
            break;
        }
        mini += 1LL * x * i;
        sisa -= x;
    }
    vector<int> ve;

    for (int i = sampai - 1; i >= 0; i--)
    {
        long long x = sampai - i;
        if (x & 1)
        {
            if (sisa > 0)
            {
                sisa -= 1;
                batas[i] = x;
            }
        }
    }

    long long dari = 0;
    long long tadi = 0;
    long long pangkat = 0;
    cout << mini << '\n';
    while (q--)
    {
        long long x;
        cin >> x;
        long long sisa = x - tadi;
        while (sisa > 0)
        {
            long long bat;
            if (batas.count(pangkat))
                bat = batas[pangkat];
            else
            {
                long long pembilang = (sampai - 1) - pangkat;
                if (pembilang % 2 == 0)
                    pembilang -= 1;
                bat = pembilang;
            }

            long long brp = bat - dari;
            if (sisa > brp)
            {
                sisa -= brp;
                dari = (bat - 1) / 2;
                pangkat += 1;
                continue;
            }
            long long jadi = dari + sisa;
            long long pang = pangkat;
            while (jadi % 2 == 0)
            {
                pang += 1;
                jadi /= 2;
            }
            cout << (jadi + pang) << '\n';

            dari = dari + sisa;
            tadi = x;
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    int tc = 0;
    while (t--)
    {
        // solve(++tc);
        solve2(++tc);
    }
}