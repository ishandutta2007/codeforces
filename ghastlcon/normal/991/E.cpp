#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 10
#define int long long
using namespace std;

int c[N];
vector<int> v;
int k, o;

int C(int n, int m)
{
    int i, o;

    if(m > n)
        return 0;

    for(i = o = 1;i <= m;i ++)
        o *= n - i + 1;
    for(i = 1;i <= m;i ++)
        o /= i;

    return o;
}

void DFS(int x)
{
    int i, s, k;

    if(x == (signed)v.size())
    {
        for(i = s = 0; i < (signed)v.size(); i ++)
            s += c[i];
        for(i = 0, k = 1; i < (signed)v.size(); i ++)
        {
            k *= C(s - (::k && !i), c[i]);
            s -= c[i];
        }
        o += k;

        return;
    }

    for(i = 1; i <= v.at(x); i ++)
    {
        c[x] = i;
        DFS(x + 1);
    }

    return;
}

signed main(void)
{
    int n;
    int i;

    cin >> n;
    for(k = n; k; k /= 10)
        c[k % 10] ++;
    for(i = 0; i < N; i ++)
        if(c[i])
            v.push_back(c[i]);
    k = c[0];

    DFS(0);
    cout << o << endl;

    return 0;
}