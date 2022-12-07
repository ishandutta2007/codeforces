#include <iostream>

using namespace std;

int n, k, t;
bool wf[20];
int rw[20][20], rr[20][20], rk[20] = {0};
int cnt, mr;

void go(int h)
{
    if (h == n)
        return;
    go(h + 1);
    for (int i = 0; i < rk[h]; ++i)
        if (wf[rw[h][i]] && (rr[h][i] <= mr))
        {
            if (++cnt >= t)
                return;
            wf[rw[h][i]] = false;
            mr -= rr[h][i];
            go(h + 1);
            mr += rr[h][i];
            wf[rw[h][i]] = true;
            if (cnt >= t)
                return;
        }
}

bool count(int maxr)
{
    int i;
    for (i = 0; i < n; ++i)
        wf[i] = true;
    cnt = 1;
    mr = maxr;
    go(0);
    return cnt >= t;
}

void bs(int l, int r)
{
    int m;
    while (l < r)
    {
        m = (l + r) / 2;
        if (count(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
}

int main(void)
{
    cin >> n >> k >> t;
    int sum = 0, mx = 0, h, w, r;
    for (int i = 0; i < k; ++i)
    {
        cin >> h >> w >> r;
        --h;
        --w;
        rw[h][rk[h]] = w;
        rr[h][rk[h]++] = r;
        sum += r;
        if (r > mx)
            mx = r;
    }
    if (n * mx < sum)
        sum = n * mx;
    bs(0, sum);
    return 0;
}