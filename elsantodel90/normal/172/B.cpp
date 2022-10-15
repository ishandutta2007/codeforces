#include <iostream>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)

typedef long long tint;

const int MAX = 1000000;

char v[MAX];

int main()
{
    tint a,b,m,r;
    cin >> a >> b >> m >> r;
    forn(i,m) v[i] = 0;
    int t = 1;
    while (!v[r])
    {
        v[r] = t++;
        r = (a*r + b)%m;
    }
    cout << t - v[r] << endl;
    return 0;
}