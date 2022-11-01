#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)
typedef long long int ll;

const int maxn = 20;

int n;
int a [maxn];

int main()
{
    cin >> n;
    REP(i, 0, n) cin >> a[i];
    int tr;
    REP(mask, 0, (1<<n) - 1)
    {
        tr = 0;
        REP(i, 0, n)
        {
            if(mask & (1<<i))
            {
                tr += a[i];
            }
            else
            {
                tr -= a[i];
            }
            if(tr < 0) tr += 360;
            if(tr >= 360) tr -= 360;
        }
        if(tr == 0)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}