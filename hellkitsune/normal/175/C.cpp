#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct fig
{
    int c;
    long long k;
};

bool operator < (const fig &a, const fig &b)
{
    return a.c < b.c;
}

int n, t;
long long p[101];
long long k[1001] = {0};
long long score = 0;
vector<fig> vk;

int main()
{
    int i, j, q;
    long long cur = 0;
    cin >> n;
    for (i = 0; i < n; ++i)
    {
        cin >> j >> q;
        k[q] += j;
    }
    cin >> t;
    for (i = 0; i < t; ++i)
        cin >> p[i];
    p[t] = 1000000000000000ll;
    q = 0;
    for (i = 0; i <= 1000; ++i)
        if (k[i] > 0)
        {
            fig f = {i, k[i]};
            vk.push_back(f);
            ++q;
        }
    sort(vk.begin(), vk.end());
    j = 0;
    for (i = 0; i < q; ++i)
    {
        while (cur + vk[i].k > p[j])
        {
            score += (p[j] - cur) * 1ll * (j + 1) * 1ll * vk[i].c;
            vk[i].k -= p[j] - cur;
            cur = p[j];
            ++j;
        }
        score += vk[i].k * 1ll * (j + 1) * 1ll * vk[i].c;
        cur += vk[i].k;
    }
    cout << score;
    return 0;
}