#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

struct cplx
{
    double a, b;
    cplx operator+ (const cplx& o) const
    {
        return (cplx){a+o.a, b+o.b};
    }
    cplx operator- (const cplx& o) const
    {
        return (cplx){a-o.a, b-o.b};
    }
    cplx operator* (const cplx& o) const
    {
        return (cplx){a*o.a-b*o.b, a*o.b+b*o.a};
    }
};

int lg2(int n)
{
    int ret=0;
    while((1<<ret)<n)
        ret++;
    return ret;
}

void fft(int n, cplx A[], int invert)
{
    int lgn=lg2(n);
    for(int i=0; i<n; i++)
    {
        int x=0;
        for(int j=0; j<lgn; j++)
            x|=((i>>j)&1)<<(lgn-j-1);
        if(x<i)
            swap(A[x], A[i]);
    }
    static double PI=acos(-1.0);
    static cplx w[1048576];
    w[0]=(cplx){1, 0};
    for(int len=2; len<=n; len*=2)
    {
        int hlen=len/2;
        cplx root=(cplx){cos(invert*2*PI/len), sin(invert*2*PI/len)};
        for(int i=1; i<hlen; i++)
            w[i]=w[i-1]*root;
        for(int i=0; i<n; i+=len)
            for(int j=0; j<hlen; j++)
            {
                cplx u=A[i+j], v=A[i+j+hlen]*w[j];
                A[i+j]=u+v;
                A[i+j+hlen]=u-v;
            }
    }
}

void convolve(int n, int A[], int B[], int C[])
{
    static cplx X[2097152], Y[2097152];
    for(int i=0; i<n; i++)
        X[i].a=A[i], X[i].b=0, Y[i].a=B[i], Y[i].b=0;
    fft(n, X, 1);
    fft(n, Y, 1);
    for(int i=0; i<n; i++)
        X[i]=X[i]*Y[i];
    fft(n, X, -1);
    for(int i=0; i<n; i++)
        C[i]=round(X[i].a/n);
}

int N, M;
int A[2097152], B[2097152];

int main()
{
    scanf("%d%d", &N, &M);
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        A[a]=1;
    }
    int n=M;
    if(n!=(1<<lg2(n)))
        n=1<<lg2(n);
    n*=2;
    convolve(n, A, A, B);
    for(int i=1; i<=M; i++)
        if(B[i] && !A[i])
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    int ans=0;
    for(int i=1; i<=M; i++)
        if(A[i] && !B[i])
            ans++;
    printf("%d\n", ans);
    for(int i=1; i<=M; i++)
        if(A[i] && !B[i])
            printf("%d ", i);
    printf("\n");
    return 0;
}