#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

int n;

int trgcd = -1;

int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a % b);
}

vector <int> svi;
vector <int> brojevi;

int main()
{
    int trp = 0;
    REP(i, 0, 60) brojevi.push_back(i);
    srand(time(NULL));
    cin >> n;
    int lo = 0, hi = 1e9, mid;
    int odg;
    while(lo < hi)
    {
        mid = (lo + hi) / 2;
        printf("> %d\n", mid);
        fflush(stdout);
        scanf("%d", &odg);
        if(odg) lo = mid + 1;
        else hi = mid;
    }
    REP(i, 0, 30)
    {
        int q = (long long) rand() * brojevi[i] % n;
        trp++;
        q++;
        if(i == 0) q = 1;
        else if(i == 1) q = n;
        printf("? %d\n", q);
        fflush(stdout);
        scanf("%d", &odg);
        if(trgcd == -1) trgcd = lo - odg;
        else trgcd = gcd(lo - odg, trgcd);
        REP(j, 0, (int)svi.size())
        {
            trgcd = gcd(abs(svi[j] - odg), trgcd);
        }
        svi.push_back(odg);
    }
    printf("! %d %d", lo - (n - 1) * trgcd, trgcd);
    fflush(stdout);
    return 0;
}