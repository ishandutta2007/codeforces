#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define PB push_back
#define MP make_pair
#define REP(i, n) for (int i = 0; i < n; ++i)

using namespace std;

const long long MUL = 1231237;
const long long MOD = 1000000007;

long long power[200007];
long long has[200007 * 4];
int num[200007 * 4], L[200007 * 4], R[200007 * 4];

void build(int left, int right, int x)
{
    L[x] = R[x] = -1;
    num[x] = has[x] = 0;
    if (left < right)
    {
        int mid = (left + right) >> 1;
        build(left, mid, x*2);
        build(mid+1, right, x*2+1);
    }
}

void add(int left, int right, int aim, int x, int val, int where)
{
    if (left == right)
    {
        num[x] += val;
        if (num[x])
            L[x] = R[x] = where;
        else
            L[x] = R[x] = -1;

        return;
    }

    int mid = (left + right) >> 1;
    if (aim <= mid) add(left, mid, aim, x*2, val, where);
    else add(mid+1, right, aim, x*2+1, val, where);

    if (num[x*2]) L[x] = L[x*2]; else L[x] = L[x*2+1];
    if (num[x*2+1]) R[x] = R[x*2+1]; else R[x] = R[x*2];

    if (num[x*2] && num[x*2+1])
        has[x] = (has[x*2]*power[num[x*2+1]] + has[x*2+1] + (L[x*2+1]-R[x*2])*power[num[x*2+1]-1]) % MOD;
    else if (num[x*2])
        has[x] = has[x*2];
    else
        has[x] = has[x*2+1];

    num[x] = num[x*2] + num[x*2+1];
}

int a[200007], b[200007], idx[200007], diff[200007];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> b[i];
    REP(i, m) --b[i];
    if (1 == n)
    {
        cout << m << endl;
        return 0;
    }

    REP(i, n-1) diff[i] = a[i+1]-a[i];
    REP(j, m) idx[b[j]] = j;

    power[0] = 1;
    REP(i, n+1) power[i+1] = power[i] * MUL % MOD;
    long long aim = 0;
    REP(i, n-1) aim = (aim * MUL + diff[i]) % MOD;

    if (aim < 0) aim += MOD;

    int ans = 0;
    build(0, m-1, 1);
    REP(i, m)
    {
        add(0, m-1, idx[i], 1, 1, i);
        if (i >= n)
            add(0, m-1, idx[i-n], 1, -1, i);
        if (i >= n-1)
        {
            if ((has[1]+MOD)%MOD == aim)
                ++ans;
            //cout << aim << " " << has[1] << endl;
        }
    }

    cout << ans << endl;
    return 0;
}