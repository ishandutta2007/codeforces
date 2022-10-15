#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)

typedef unsigned long long utint;

const utint MOD = 0x4C1AF3CF52326634LL;

// Trabajamos modulo un numero de 64 bits al azar (no 'tan' al azar: MOD * 3 no da overflow, pero igual el numero es grande),
// a priori no hay forma de que nos caguen sin adivinar nuestros numeros aleatorios (o poner una cantidad enorme de casos de prueba).
// Se pueden usar 2 o mas de estos long long coprimos para obtener un hash de 128, 256, etc bits. Con n bits, asumiendo probabilidad uniforme, por
// "paradoja de los cumpleanios", no hay chance relevante de colision hasta que no nos acercamos a una cantidad de 2^(n/2) de hashes generados.
// Con 64 bits en este problema (y casi cualquiera imaginable de competencia) estamos muy lejos de eso. Con 128 bits estariamos ridiculamente lejos de eso.
// (Pensar que para firmas digitales de cosas grosas grosas, se usan hashes por ejemplo de 256 bits como el SHA-2, que serian solo 4 long long).

const int MAXLEN = 1000000;

char s[MAXLEN];

const char* answer[] = {"NO", "YES"};

int main()
{
    #ifdef ACMTUYO
        freopen("entrada.in","r",stdin);
    #endif
    int n,m;
    scanf("%d%d", &n, &m);
    map<int, set<utint> > hashes;
    forn(cant,n)
    {
        scanf("%s", s);
        int L = strlen(s);
        utint H = 0;
        forn(i, L) H = (((H * 3) % MOD) + utint(s[i] - 'a')) % MOD;
        hashes[L].insert(H);
    }
    forn(cant,m)
    {
        scanf("%s", s);
        int L = strlen(s);
        utint H = 0;
        forn(i, L) H = (((H * 3) % MOD) + utint(s[i] - 'a')) % MOD;
        utint pot3 = 1;
        bool esta = false;
        dforn(i, L)
        {
            forn(j, 3)
            if (j != s[i] - 'a')
            {
                utint nH = ((H + (pot3 * utint(j)) % MOD) % MOD + MOD - (pot3 * utint(s[i] - 'a')) % MOD) % MOD;
                if (hashes[L].find(nH) != hashes[L].end())
                {
                    esta = true;
                    goto salir;
                }
            }
            pot3 *= 3;
            pot3 %= MOD;
        }
salir:  printf("%s\n", answer[esta]);
    }
    return 0;
}