#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const double PI = 2*acos(0);

struct comp
{
    double x, y;
    comp(): x(0), y(0) {}
    comp(double xx, double yy): x(xx), y(yy) {}
};

inline comp operator + (comp a, comp b) { return comp(a.x + b.x, a.y + b.y); }
inline comp operator - (comp a, comp b) { return comp(a.x - b.x, a.y - b.y); }
inline comp operator * (comp a, comp b) { return comp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
inline void operator /= (comp& a, double x) {a.x /= x; a.y /= x;}
inline comp conj(comp a) { return comp(a.x, -a.y); }

const int MAX_N = 1 << 20;
int rev[MAX_N];
comp roots[MAX_N];

void preCalc(int N, int BASE){
    for (int i = 1; i < N; ++i) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (BASE - 1));
    int NN = N >> 1;
    roots[NN] = comp(1, 0);
    roots[NN + 1] = comp(cos(2 * PI / N), sin(2 * PI / N));
    for (int i = 2; i < NN; ++i) roots[NN + i] = roots[NN + i - 1] * roots[NN + 1];
    for (int i = NN - 1; i > 0; --i) roots[i] = roots[2 * i];
}

void fft( comp *a, int N, bool invert ){
    if (invert) rep(i, 0, N) a[i] = conj(a[i]);
    rep(i, 0, N) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < N; k *= 2){
        for (int i = 0; i < N; i += 2 * k){
            rep(j, 0, k){
                comp B = a[i + j + k] * roots[k + j];
                a[i + j + k] = a[i + j] - B;
                a[i + j] = a[i + j] + B;
            }
        }
    } 
    if(invert) rep(i, 0, N) a[i] /= N;
}

void multiply_real( comp *a, int n, comp *b, int m, comp *c, int &N ){
    int base = 0;
    N = 1;
    while (N < n+m-1) base++, N <<= 1;
    preCalc(N, base);

    rep( i, 0, m ) a[i] = comp( a[i].x, b[i].x );
    fft(a, N, 0);
    rep( i, 0, N ) {
        int j = (N - i) & (N - 1);
        c[i] = (a[i] * a[i] - conj(a[j] * a[j])) * comp(0, -0.25);
    }
    fft(c, N, 1);
}

void corrige( comp* v, int n ){
    rep( i, 0, n ){
        v[i] = comp( fabs( v[i].x ) > 1e-3, 0 );
    }
}

comp AA[MAX_N], BB[MAX_N], CC[MAX_N];

int main() {
    
    int n, k, u;
    
    while( scanf("%d%d", &n, &k ) != EOF ){
        comp *a = AA, *ans = BB, *c = CC;
        ans[0] = comp(1, 0);
        int a_size = 1011;
        int ans_size = 1;

        rep( i, 0, n ){
            scanf("%d", &u );
            a[u] = comp( 1, 0 );
        }
        while( k ){
            if( k&1 ) multiply_real( ans, ans_size, a, a_size, c, ans_size ), swap(ans, c), corrige(ans, ans_size);
            multiply_real( a, a_size, a, a_size, c, a_size ), swap(a,c), corrige(a, a_size);
            k >>= 1;
        }
        bool a1 = 0;
        rep( i, 0, ans_size ){
            if( fabs( ans[i].x ) < 1e-9 ) continue;
            if( a1 ) printf(" ");
            a1 = 1;
            printf("%d", i );
        }
        printf("\n");
    }
     
}