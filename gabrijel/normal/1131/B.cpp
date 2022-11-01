#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 100100;
const int inf = 1e9 + 100;

int x = 0, y = 0, z;

int rj = 1;

int n;

int main()
{
    cin >> n;
    int a, b, c;
    REP(i, 0, n)
    {
        cin >> a >> b;
        c = min(a, b);
        z = max(x, y);
        if(c >= z)
        {
            rj += c - z + 1;
            if(x == y) rj--;
        }
        x = a;
        y = b;
    }
    cout << rj << endl;
    return 0;
}