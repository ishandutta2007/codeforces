#include <bits/stdc++.h>

using namespace std;

int N;
long double M[100000];
long double m[100000];
long double A[100000];
long double B[100000];

long double getsqrt(long double x)
{
    long double lo = 0.0, mid, hi = max(1.0L, x);
    for(int i = 0; i < 70; i++)
    {
        mid = (lo + hi) / 2;
        if(mid * mid < x)
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>M[i];
    for(int i=0; i<N; i++)
        cin>>m[i];
    double AS=0.0, BS=0.0;
    for(int i=0; i<N; i++)
    {
        long double MX = M[i];
        long double mX = m[i];
        long double c = (MX * BS + mX * BS - MX);
        long double b = (-BS + AS + MX + mX);
        long double a = -1.0L;
        long double BX = (-b + getsqrt(b * b - 4 * a * c)) / 2 / a;
        long double AX = MX + mX - BX;
        if(fabsl(AX) < 1e-9)
            AX = 0.0;
        if(fabsl(BX) < 1e-9)
            BX = 0.0;
        A[i] = AX;
        B[i] = BX;
        AS += AX;
        BS += BX;
    }
    for(int i=0; i<N; i++)
        cout<<fixed<<setprecision(7)<<A[i]<<' ';
    cout<<'\n';
    for(int i=0; i<N; i++)
        cout<<fixed<<setprecision(7)<<B[i]<<' ';
    cout<<'\n';
    return 0;
}