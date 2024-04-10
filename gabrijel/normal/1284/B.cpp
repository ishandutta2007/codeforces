#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int inf = 1e9;

int n;

int poc, kraj, trmin;

vector <int> pocetci, krajevi;

long long int rj = 0;

int kolko;

int main()
{
    cin >> n;
    int a, x;
    kolko = n;
    REP(i, 0, n)
    {
        scanf("%d", &a);
        trmin = inf;
        bool z = 1;
        REP(j, 0, a)
        {
            scanf("%d", &x);
            if(j == 0) poc = x;
            if(j == a - 1) kraj = x;
            if(x > trmin && z)
            {
                rj += kolko * 2 - 1;
                kolko--;
                z = 0;
            }
            trmin = min(trmin, x);
        }
        if(z)
        {
            pocetci.push_back(poc);
            krajevi.push_back(kraj);
        }
    }
    sort(pocetci.begin(), pocetci.end());
    sort(krajevi.begin(), krajevi.end());
    REP(i, 0, (int)pocetci.size())
    {
        int lo = 0, hi = (int)krajevi.size(), mid;
        while(lo < hi)
        {
            mid = (lo + hi) / 2;
            if(krajevi[mid] < pocetci[i])
            {
                lo = mid + 1;
            }
            else hi = mid;
        }
        rj += lo;
    }
    cout << rj << endl;
    return 0;
}