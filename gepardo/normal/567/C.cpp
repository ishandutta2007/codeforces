#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#define INF 123456789012345678

using namespace std;

struct qst
{
    __int64 first, second;
};

__int64 f[3][1000000];
__int64 dp[3][1000000];
__int64 n;
__int64 a[1000000], q[1000000];
qst s[1000000];

void f_init(__int64 nn, __int64 id)
{
	n = nn;
	for(__int64 i = 0; i < n; i++) f[id][i] = 0;
}

__int64 f_sum(__int64 r, __int64 id)
{
	__int64 result = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		result += f[id][r];
	return result;
}

void f_inc(__int64 i, __int64 delta, __int64 id)
{
	for (; i < n; i = (i | (i + 1)))
		f[id][i] += delta;
}

__int64 f_sum(__int64 l, __int64 r, __int64 id)
{
	return f_sum(r, id) - f_sum(l - 1, id);
}

void range(__int64 n, __int64 v, __int64 &li, __int64 &ri)
{
    //cout << "range in " << v << endl;
    __int64 l, r, c = 0;
    li = -1; ri = -1;
    l = 1; r = n - 2;
    while (l + 1 < r)
    {
        __int64 m = (l + r) / 2;
        if (s[m].first < v)
             l = m + 1;
        else r = m;
        c++;
        //cout << "1: " << l << " " << r << " " << m << " " << s[m].first << endl;
    }
    if (s[r].first == v && s[r - 1].first < v) li = r;
    if (s[l].first == v && s[l - 1].first < v) li = l;

    l = 1; r = n - 2;
    while (l + 1 < r)
    {
        __int64 m = (l + r) / 2;
        if (s[m].first <= v)
             l = m;
        else r = m - 1;
        c++;
        //cout << "2: " << l << " " << r << " " << m << " " << s[m].first << endl;
    }
    if (s[r].first == v && s[r + 1].first > v) ri = r;
    if (s[l].first == v && s[l + 1].first > v) ri = l;
    //cout << "range out (" << li << "; " << ri << ")" << endl;
    //for (;;);
    //cout << c << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    __int64 n, k;
    scanf("%I64d%I64d", &n, &k);
    vector< pair<__int64, __int64> > ps(n + 2);
    ps[n] = make_pair(-INF, 0);
    ps[n + 1] = make_pair(INF, n + 1);
    for (int i = 0; i < n; i++)
    {
        scanf("%I64d", &a[i]);
        ps[i].first = a[i];
        ps[i].second = i;
    }
    sort(ps.begin(), ps.end());
    for (int i = 1; i <= n; i++) q[ps[i].second] = i;
    for (int i = 0; i < n + 2; i++)
    {
        s[i].first = ps[i].first;
        s[i].second = ps[i].second;
    }
    f_init(n + 2, 0);
    f_init(n + 2, 1);
    f_init(n + 2, 2);
    for (int i = 0; i < n; i++) dp[0][i] = 1;
    for (int id = 1; id < 3; id++)
        for (int i = 0; i < n; i++)
        {
            //cout << "dp " << id << " " << i << endl;
            dp[id][i] = 0;
            f_inc(q[i], dp[id - 1][i], id - 1);
            if (a[i] != 0)
            {
                if (a[i] % k != 0) continue;
            }
            __int64 li, ri, v;
            if (a[i] != 0) v = a[i] / k; else v = 0;
            range(n + 2, v, li, ri);
            if (li > ri) continue;
            if (li < 0) continue;
            if (ri < 0) continue;
            if (s[li].first != v) continue;
            if (s[ri].first != v) continue;
            dp[id][i] = f_sum(li, ri, id - 1);
            if (li <= q[i] && q[i] <= ri) dp[id][i] -= dp[id - 1][i];
            //cout << "dp " << id << " " << i << " " << dp[id][i] << " " << v << endl;
        }
    __int64 sum = 0;
    for (int i = 0; i < n; i++)
        sum += dp[2][i];
    cout << sum;
}