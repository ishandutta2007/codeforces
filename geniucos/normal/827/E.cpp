#include<bits/stdc++.h>

using namespace std;

int rev[1 << 20], broken[500009];
char sir[500009];
double PI = acos (-1.0);

typedef complex < double > cx;
cx rootOfUnity (int N) {return cx (cos (2.0 * PI / N), sin (2.0 * PI / N));}
cx aa[1 << 20], bb[1 << 20];

void dft (int N, cx a[], bool rv)
{
    for (int i=0; i<N; i++)
        if (i < rev[i])
            swap (a[i], a[rev[i]]);
    for (int l=2; l<=N; l+=l)
    {
        cx omega;
        if (rv) omega = rootOfUnity (-l);
        else omega = rootOfUnity (l);
        for (int i=0; i<N; i+=l)
        {
            cx p = 1;
            for (int j=0; j<l/2; j++)
            {
                cx u = a[i + j], v = a[i + j + l / 2] * p;
                a[i + j] = u + v;
                a[i + j + l / 2] = u - v;
                p *= omega;
            }
        }
    }
    if (rv)
    {
        for (int i=0; i<N; i++)
            a[i] /= N;
    }
}

vector < int > convolution (vector < int > a, vector < int > b)
{
    int N = 1, E = 0;
    while (a.size () + b.size () > N) N += N, E ++;
    a.resize (N), b.resize (N);
    for (int i=0; i<N; i++)
    {
        rev[i] = rev[i >> 1] >> 1;
        if (i & 1) rev[i] |= 1 << (E - 1);
    }
    for (int i=0; i<N; i++)
        aa[i] = cx (a[i]), bb[i] = cx (b[i]);
    dft (N, aa, 0), dft (N, bb, 0);
    for (int i=0; i<N; i++)
        aa[i] *= bb[i];
    dft (N, aa, 1);
    vector < int > c;
    for (int i=0; i<N; i++)
        c.push_back ((int) (real (aa[i]) + 0.5));
    return c;
}

void prnt (vector < int > v) {for (int i=0; i<v.size (); i++) printf ("%d%c", v[i], " \n"[i == v.size () -1]);}
void rd (vector < int > &v) {v.clear (); int l, x; scanf ("%d", &l); for (int i=0; i<l; i++) scanf ("%d", &x), v.push_back (x);}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*vector < int > a, b, c;
rd (a), rd (b);
c = convolution (a, b);
prnt (c);*/

int Tests;
scanf ("%d", &Tests);
while (Tests --)
{
    int L;
    scanf ("%d\n", &L);
    scanf ("%s", sir);
    vector < int > a (L, 0), b (L, 0);
    for (int i=0; i<L; i++)
        if (sir[i] == 'V') a[i] = 1;
        else
        if (sir[i] == 'K') b[L - i - 1] = 1;
  //  prnt (a), prnt (b), printf (" = ");
    vector < int > c = convolution (a, b);
//    prnt (c);
    for (int i=1; i<=L; i++)
        broken[i] = 0;
    for (int i=0; i<c.size (); i++)
    if (c[i] > 0)
    {
        int d = i - (L - 1);
        if (d < 0) d = -d;
        broken[d] = 1;
    }
    for (int i=L; i>=1; i--)
        for (int j=i + i; j<=L; j+=i)
            broken[i] |= broken[j];
    int sz = 0;
    for (int i=1; i<=L; i++)
        sz += (broken[i] == 0);
    printf ("%d\n", sz);
    for (int i=1; i<=L; i++)
        if (broken[i] == 0)
            printf ("%d%c", i, " \n"[--sz == 0]);
}

return 0;
}