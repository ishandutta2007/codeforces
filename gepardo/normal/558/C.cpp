#include <iostream>
#include <cstdlib>

using namespace std;

int n, a[200000], mops = 2147483647;
int done[10000000] = {};

int divider(int a, int b)
{
    int q;
    if (a > b)
    {
        if (a % b != 0) return -1;
        q = a / b;
    }
    else
    {
        if (b % a != 0) return -1;
        q = b / a;
    }
    int op = 0;
    while (q > 1)
    {
        if (q % 2 == 1) return -1;
        op++;
        q = q / 2;
    }
    return op;
}

int tryOn(int from, int to)
{
    int qfrom = from, op = 0;
    while (qfrom > 0)
    {
        int au = divider(qfrom, to);
        if (au >= 0) return (op + au);
        qfrom = qfrom / 2;
        op++;
    }
    return -1;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int uv = a[0];
    for (int i1 = 0; i1 < 21; i1++)
    {
        int q = uv;
        for (int i2 = 0; i2 < 21; i2++)
        {
            if (done[q] != 0) continue;
            done[q] = 1;
            int ops = 0;
            bool yes = true;
            for (int j = 0; j < n; j++)
            {
                int w = tryOn(a[j], q);
                if (w < 0)
                {
                    yes = false;
                    break;
                }
                ops += w;
            }
            if (!yes) continue;
            if (ops < mops) mops = ops;
            q = q * 2;
            if (q > 200000) break;
        }
        uv = uv / 2;
        if (uv < 1) break;
    }
    cout << mops;
}