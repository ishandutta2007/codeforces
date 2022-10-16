#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define all(x) x.begin(), x.end()
#define f(i,a,b) for(int i = (a); i <= (b); i++)
#define fd(i,a,b) for(int i = (a); i >= (b); i--)
#define mp make_pair
#define faster_io() ios_base::sync_with_stdio(false)
#define pb push_back
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define vii vector<pair<int,int>>

const int INF = 1000000002;
const ll INFLL = 100000000000000000ll;
const ll MOD = 1000000007;

// ----------------------------------------------------------------------------------------------------------

struct Matrix
{
    int a, b, c, d;
    Matrix(int _a=1, int _b=0, int _c=0, int _d=1) : a(_a), b(_b), c(_c), d(_d) { }
};

Matrix operator * (Matrix x, Matrix y)
{
    Matrix ret
    (
        ((ll)x.a * (ll)y.a + (ll)x.b * (ll)y.c) % MOD, ((ll)x.a * (ll)y.b + (ll)x.b * (ll)y.d) % MOD,
        ((ll)x.c * (ll)y.a + (ll)x.d * (ll)y.c) % MOD, ((ll)x.c * (ll)y.b + (ll)x.d * (ll)y.d) % MOD
    );

    return ret;
}

Matrix operator + (Matrix x, Matrix y)
{
    return Matrix((x.a + y.a) % MOD, (x.b + y.b) % MOD, (x.c + y.c) % MOD, (x.d + y.d) % MOD);
}

Matrix pow(Matrix a, int e)
{
    if(e == 0) return Matrix();
    Matrix x = pow(a, e >> 1);
    x = x*x;
    if(e & 1) x = x * a;
    return x;
}

const int SIZE = 265000;
Matrix L[SIZE], T[SIZE];

int N, Q;

Matrix query(int l, int r, int n, int a, int b)
{
    if(a > r || b < l) return Matrix(0,0,0,0);
    
    if(a >= l && b <= r) return T[n];

    if(L[n].b > 0)
    {
        T[2*n] = T[2*n]*L[n];
        T[2*n+1] = T[2*n+1]*L[n];
        L[2*n] = L[2*n]*L[n];
        L[2*n+1] = L[2*n+1]*L[n];
        L[n] = Matrix();
    }

    int mid = (a+b) / 2;
    Matrix ql = query(l,r,2*n,a,mid);
    Matrix qr = query(l,r,2*n+1,mid+1,b);

    return ql+qr;
}

void update(int l, int r, Matrix m, int n, int a, int b)
{
    if(a > r || b < l) return;
    if(a >= l && b <= r)
    {
        L[n] = L[n]*m;
        T[n] = T[n]*m;
        return;
    }

    if(L[n].b > 0)
    {
        T[2*n] = T[2*n]*L[n];
        T[2*n+1] = T[2*n+1]*L[n];
        L[2*n] = L[2*n]*L[n];
        L[2*n+1] = L[2*n+1]*L[n];
        L[n] = Matrix();
    }

    int mid = (a+b) / 2;
    update(l,r,m,2*n,a,mid);
    update(l,r,m,2*n+1,mid+1,b);

    T[n] = T[2*n] + T[2*n+1];
}

int main()
{
    Matrix id(1,1,1,0);
    cin >> N >> Q;
    f(i,1,N)
    {
        int x;
        scanf("%d", &x);
        Matrix m = pow(id,x);
        update(i,i,m,1,1,N);
    }
    while(Q--)
    {
        int t;
        scanf("%d", &t);
        if(t == 1)
        {
            int l,r,x;
            scanf("%d %d %d", &l, &r, &x);
            Matrix m = pow(id,x);
            update(l,r,m,1,1,N);
        }
        else
        {
            int l,r;
            scanf("%d %d", &l, &r);
            Matrix m = query(l,r,1,1,N);
            printf("%d\n", m.b);
        }
    }
}