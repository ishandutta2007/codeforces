#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxk = 100100;

int b, k;

int a[maxk];

bool paran = 1;

int main()
{
    cin >> b >> k;
    REP(i, 0, k)
    {
        scanf("%d", &a[i]);
    }
    REP(i, 0, k)
    {
        if(i < k - 1)
        {
            if(b % 2 == 0) continue;
            if(a[i] % 2 == 0) continue;
            paran = !paran;
            continue;
        }
        else
        {
            if(a[i] % 2 == 0) continue;
            paran = !paran;
            continue;
        }
    }
    if(paran)
    {
        cout << "even" << endl;
    }
    else
    {
        cout << "odd" << endl;
    }
    return 0;
}