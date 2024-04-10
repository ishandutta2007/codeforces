#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

using namespace std;

namespace FFT
{
    typedef double tipo;
    // Tipo debe ser un tipo de punto flotante

    struct Comp
    {
        tipo r,i;
        Comp() : r(0), i(0) {}
        Comp(tipo rr) : r(rr), i(0) {}
        Comp(tipo rr, tipo ii) : r(rr), i(ii) {}
        Comp operator + (const Comp &o) const { return Comp(r + o.r, i + o.i); }
        Comp operator - (const Comp &o) const {	return Comp(r - o.r, i - o.i); }
        Comp operator * (const Comp &o) const {	return Comp(r * o.r - i * o.i,r * o.i + o.r * i); }
        Comp & operator += (const Comp &o) { return *this = *this + o; }
        Comp & operator *= (const Comp &o) { return *this = *this * o; }
    };

    #define MAXN (1<<20)	// Debe ser potencia de 2
                            // Si se esta usando convolucion, debe ser
                            // al menos 2 * n

    const tipo PI = 4.0 * atan(1.0);

    unsigned bTabla[(1<<16)]; 	// Es importante que sea unsigned para que al hacer shift right
                                // haga shift logico y no shift aritmetico.

    // Se llama a llenarTabla una vez al comienzo del programa.

    void llenarTabla()
    {
        bTabla[0] = 0;
        forn(i,16)
        {
            int s = (1<<i);
            forn(j,s) bTabla[s + j] = (bTabla[j] *= 2)+1;
        }
    }

    struct Fft
    {
        // Tipo debe ser un tipo de punto flotante
        int n,nk;
        Comp v[MAXN];
        Comp *init(int nn)
        {
            for(n = 1, nk = 32; n < nn; n *= 2, nk--);
            forn(i, n) v[i] = 0;
            return v;
        }
        Comp *fft()
        {
            forn(i,n)
            {
                int j = (((bTabla[i&0xFFFF] << 16) | bTabla[i>>16]) >> nk);
                if (j > i) swap(v[i],v[j]);
            }
            for(int i=2;i<=n; i+=2)
            {
                int s = 1, x = i;
                while (x%2 == 0)
                {
                    x /= 2;
                    Comp w1 = 1.0;
                    const Comp w(cos(PI/tipo(s)),-sin(PI/tipo(s)));
                    Comp *A = v+i-2*s, *B = v+i-s, *FIN = v+i;
                    // Cuello de botella : este for.
                    // En particular, las dos multiplicaciones.
                    for(;B != FIN;A++,B++)
                    {
                        Comp X = *A, Y = w1 * *B;
                        *A += Y;
                        *B = X - Y;
                        w1 *= w;
                    }
                    s *= 2;
                }
            }
            
            return v;
        }
        Comp *invfft()
        {
            reverse(v+1,v+n);
            forn(i,n) v[i] *= 1.0 / tipo(n);
            return fft();
        }
        // Uso:
        // Se llama a init, se llena el vector en el puntero devuelto.
        // Se llama a fft o a invftt, segun lo buscado.
        // El output aparece en el puntero devuelto.
    };

    struct Convolucion
    {
        // Tipo debe ser un tipo de punto flotante
        Fft fft;
        Comp v[MAXN]; // Se usa el MAXN de fft
        Comp* init(int n)
        {
            return fft.init(2*n);
        }
        Comp *next()
        {
            fft.fft();
            forn(i, fft.n) {v[i] = fft.v[i]; fft.v[i] = 0; }
            return fft.v;
        }
        Comp *conv()
        {
            fft.fft();
            forn(i,fft.n)
                fft.v[i] *= v[i];
            return fft.invfft();
        }
        // Uso:
        // Se llama a init, se llena el primer vector en el puntero devuelto.
        // Se llama a next, se llena el segundo vector en el puntero devuelto.
        // Se llama a conv, la convolucion aparece en el puntero devuelto.
    };
};

FFT::Convolucion conv;

vector<double> poly[128];

int main() 
{
    #ifdef ACMTUYO
        if (!freopen( "c.in" ,"r",stdin)) return 0;
    #endif
    FFT::llenarTabla();
    int _sc = 0;
    int N,M;
    while (scanf("%d%d", &N, &M) != EOF)
    {
        int totalRank = 0;
        forn(i, N)
        {
            int rank; _sc = scanf("%d", &rank);
            if (M > 1)
            {
                poly[i].resize(M);
                rank--;
                totalRank += rank;
                forn(j, M) poly[i][j] = 1.0 / FFT::tipo(M-1);
                poly[i][rank] = 0.0;
            }
        }
        if (M == 1)
        {
            printf("1.0\n");
        }
        else
        {
            
            /*
            vector<double> ret(1,1.0);
            forn(i,N)
            {
                int A = ret.size();
                int B = poly[i].size();
                FFT::Comp * p = conv.init(max(A,B));
                forn(j, ret.size()) p[j] = ret[j];
                p = conv.next();
                forn(j, poly[i].size())  p[j] = poly[i][j];
                p = conv.conv();
                ret.resize(A+B);
                forn(j, ret.size()) ret[j] = p[j].r;
            }
            */
            
            while (N > 1)
            {
                int K = 0;
                forn(i,N/2)
                {
                    int A = poly[2*i].size();
                    int B = poly[2*i+1].size();
                    FFT::Comp * p = conv.init(max(A,B));
                    forn(j, A) p[j] = poly[2*i][j];
                    p = conv.next();
                    forn(j, B) p[j] = poly[2*i+1][j];
                    p = conv.conv();
                    poly[K].resize(A+B);
                    forn(j, A+B) poly[K][j] = p[j].r;
                    K++;
                }
                if (N%2)
                    poly[K++] = poly[N-1];
                N = K;
            }
            
            double expected = 0.0;
            forn(i, totalRank) expected += poly[0][i];
            expected = 1.0 + double(M-1) * expected;
            printf("%.15lf\n", (double)expected);
        }
    }
    if (_sc) return 0;
    return 0;
}