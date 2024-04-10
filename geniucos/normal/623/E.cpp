#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#define S 1000

using namespace std;

int N, E, n, K, mod, inv[100009], fac[100009], put[100009], dp[100009], baza[100009], rev[100009];
long double PI = acos (-1.0);
bool DBG;

struct comp
{
    double a, b;
    long long get_val () {return (long long) ((double)a + 0.5);}
    comp (): a (0.0), b (0.0) {}
    comp (int N){a = cos ((double)2.0 * PI / N), b = -sin ((double)2.0 * PI / N);}
    comp (double x): a (x), b  (0.0) {}
    comp (double _a, double _b): a (_a), b (_b) {}
};
comp operator + (comp c1, comp c2) {return comp (c1.a + c2.a, c1.b + c2.b);}
comp operator * (comp c1, comp c2) {return comp (c1.a * c2.a - c1.b * c2.b, c1.a * c2.b + c1.b * c2.a);}
comp operator - (comp c1, comp c2) {return comp (c1.a - c2.a, c1.b - c2.b);}
comp operator - (comp c) {return comp (-c.a, -c.b);}
void init (comp *A) {A = new comp[N + 1];}

comp A[3][100009], B[3][100009], aux[100009];

void FFT (comp *A, bool inv)
{
    for (int i=0; i<N; i++)
        if (i < rev[i]) swap (A[i], A[rev[i]]);
    for (int l=2; l<=N; l <<= 1)
    {
        comp omega = comp (l);
        if (inv) omega = comp (-l);
        for (int i=0; i<N; i+=l)
        {
            comp put = comp (1.0);
            for (int j=0; j<l / 2; j++)
            {
                comp u = A[i + j], v = A[i + j + l / 2] * put;
                A[i + j] = u + v;
                A[i + j + l / 2] = u - v;
                put = put * omega;
            }
        }
    }
    if (inv)
    {
        for (int i=0; i<N; i++)
            A[i] = A[i] * comp (1.0 / N);
    }
}

/*void DFT (comp *A, int step, int N, comp *B)
{
    if (N == 1)
    {
        *B = *A;
        return ;
    }
    DFT (A, step << 1, N >> 1, B), DFT (A + step, step << 1, N >> 1, B + (N >> 1));
    comp omega = comp (N), put = comp ((double)1.0);
    for (int i=0; i < N >> 1; i++)
    {
        comp t1 = B[i], t2 = B[i + (N >> 1)];
        B[i] = t1 + t2 * put;
        B[i + (N >> 1)] = t1 - t2 * put;
        put = put * omega;
    }
}

void Run_DFT (comp *A)
{
    DFT (A, 1, N, aux);
    for (int i=0; i<N; i++)
        A[i] = aux[i];
}

void InverseDFT (comp *A, int N, comp *B)
{
    DFT (A, 1, N, B);
    for (int i=0; i<N; i++)
        B[i] = B[i] * ((double) 1.0 / N);
    reverse (B + 1, B + N);
}*/

int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

void Multiply (int a[], int b[], int fin_ans[], int l)
{
    for (int i=0; i<N; i++)
    {
        int coef = (1LL * inv[i] * pow (2, i * l)) % mod, v1, v2;
        v1 = (1LL * a[i] * coef) % mod;
        v2 = (1LL * b[i] * inv[i]) % mod;
        for (int j=0; j<3; j++)
            A[j][i] = comp ((double) (v1 % S)), v1 /= S, B[j][i] = comp ((double) (v2 % S)), v2 /= S;
        fin_ans[i] = 0;
    }
    for (int i=0; i<3; i++)
        FFT (A[i], 0), FFT (B[i], 0);
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
        {
            for (int k=0; k<N; k++)
                aux[k] = A[i][k] * B[j][k];
            FFT (aux, 1);
            int coef = 1, auxx = i + j;
            while (auxx --) coef = (1LL * coef * S) % mod;
            for (int k=0; k<N; k++)
                fin_ans[k] = ((long long) fin_ans[k] + 1LL * coef * aux[k].get_val ()) % mod;
        }
    for (int i=0; i<N; i++)
        fin_ans[i] = (1LL * fin_ans[i] * fac[i]) % mod;
}

int comb (int N, int K)
{
    int ans = (1LL * fac[N] * inv[K]) % mod;
    ans = (1LL * ans * inv[N - K]) % mod;
    return ans;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &n, &K), mod = 1e9 + 7;
if (n > K)
{
    printf ("0\n");
    return 0;
}
fac[0] = 1, inv[0] = 1;
for (int i=1; i<=K; i++)
    fac[i] = (1LL * fac[i - 1] * i) % mod, inv[i] = pow (fac[i], mod - 2);
N = 1, E = 0; while (N <= 2 * K) N += N, E ++;
for (int i=0; i<N; i++)
    for (int k=0; k<E; k++)
        rev[i] = (rev[i] << 1) | ((i >> k) & 1);
for (int i=1; i<=K; i++)
    baza[i] = 1, dp[i] = n & 1;
if (n % 2 == 0) dp[0] = 1;
for (int i=1; (1<<i) <= n; i++)
{
    Multiply (baza, baza, baza, (1 << (i - 1)));
    if (n & (1 << i)) Multiply (dp, baza, dp, (1 << i));
}
int cnt = 0;
for (int i=1; i<=K; i++)
    cnt = ((long long) cnt + 1LL * dp[i] * comb (K, i)) % mod;
printf ("%d\n", cnt);
return 0;
}