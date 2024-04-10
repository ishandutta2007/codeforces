#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)
#define REPN(i, a, b) for(int i = a; i >= b; i--)

int w, h;
int u1, d1, u2, d2;

int main()
{
    cin >> w >> h;
    cin >> u1 >> d1 >> u2 >> d2;
    while(h)
    {
        w += h;
        if(h == d1)
        {
            w -= u1;
        }
        if(h == d2)
        {
            w -= u2;
        }
        w = max(w, 0);
        h--;
    }
    cout << w << endl;
    return 0;
}