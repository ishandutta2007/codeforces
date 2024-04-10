#include <iostream>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

typedef long long tint;

const int MAX = 11000000;

int libre[MAX];

void criba()
{
    forn(i,MAX) libre[i] = i;
    for(int i = 2;i*i < MAX; i++)
    {
        int sq = i*i;
        for(int j = sq; j < MAX ; j += sq)
            while (libre[j] % sq == 0)
                libre[j] /= sq;
    }
}

int main()
{
    criba();
    int a,n; cin >> a >> n;
    tint res = 0;
    forsn(i,a,a+n)
        res += libre[i];
    cout << res << endl;
    return 0;
}