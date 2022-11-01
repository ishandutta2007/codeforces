#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 100100;
const int maxk = 35;
const int inf = 1e9 + 100;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int baza1 = 3137;
const int baza2 = 10007;

inline int add(int a, int b, int mod)
{
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
    return a;
}

inline int mult(int a, int b, int mod)
{
    return (long long) a * b % mod;
}


int n, k;

char niz[maxn][maxk];

long long int rj = 0;

map <int, bool> ha1;
map <int, bool> ha2;

int main()
{
    cin >> n >> k;
    int trha1, trha2;
    REP(i, 0, n)
    {
        trha1 = 0;
        trha2 = 0;
        scanf("%s", niz[i]);
        REP(j, 0, k)
        {
            trha1 = mult(trha1, baza1, mod1);
            trha2 = mult(trha2, baza2, mod2);
            if(niz[i][j] == 'S') {trha1 = add(trha1, 1, mod1); trha2 = add(trha2, 1, mod2);}
            else if(niz[i][j] == 'E') {trha1 = add(trha1, 2, mod1); trha2 = add(trha2, 2, mod2);}
            else {trha1 = add(trha1, 3, mod1); trha2 = add(trha2, 3, mod2);}
        }
        ha1[trha1] = 1;
        ha2[trha2] = 1;
    }
    char tri, trj;
    REP(i, 0, n)
    {
        REP(j, i + 1, n)
        {
            trha1 = 0;
            trha2 = 0;
            REP(kk, 0, k)
            {
                trha1 = mult(trha1, baza1, mod1);
                trha2 = mult(trha2, baza2, mod2);
                trj = niz[i][kk];
                tri = niz[j][kk];
                if(tri == trj)
                {
                    if(tri == 'S') {trha1 = add(trha1, 1, mod1); trha2 = add(trha2, 1, mod2);}
                    else if(tri == 'E') {trha1 = add(trha1, 2, mod1); trha2 = add(trha2, 2, mod2);}
                    else {trha1 = add(trha1, 3, mod1); trha2 = add(trha2, 3, mod2);}
                }
                else
                {
                    if(tri != 'S' && trj != 'S')
                    {
                        trha1 = add(trha1, 1, mod1);
                        trha2 = add(trha2, 1, mod2);
                    }
                    else if(tri != 'E' && trj != 'E')
                    {
                        trha1 = add(trha1, 2, mod1);
                        trha2 = add(trha2, 2, mod2);
                    }
                    else
                    {
                        trha1 = add(trha1, 3, mod1);
                        trha2 = add(trha2, 3, mod2);
                    }
                }
            }
            if(ha1[trha1] && ha2[trha2]) rj++;
        }
    }
    cout << rj / 3 << endl;
    return 0;
}