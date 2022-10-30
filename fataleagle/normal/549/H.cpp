#include <bits/stdc++.h>

using namespace std;

double EPS=1e-50;

pair<double, double> getrange(double a[], double b[])
{
    double mini=1e300, maxi=-1e300;
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
        {
            mini=min(mini, a[i]*b[j]);
            maxi=max(maxi, a[i]*b[j]);
        }
    return make_pair(mini, maxi);
}

bool check(double a[], double b[], double c[], double d[])
{
    pair<double, double> x=getrange(a, d);
    pair<double, double> y=getrange(b, c);
    if(min(x.second, y.second)>=max(x.first, y.first)-EPS)
        return true;
    return false;
}

int main()
{
    long long a, b, c, d;
    cin>>a>>b>>c>>d;
    double lo=0.0, mid, hi=1e20;
    for(int i=0; i<50000; i++)
    {
        mid=(lo+hi)/2;
        double a0[2]={a+mid, a-mid};
        sort(a0, a0+2);
        double b0[2]={b+mid, b-mid};
        sort(b0, b0+2);
        double c0[2]={c+mid, c-mid};
        sort(c0, c0+2);
        double d0[2]={d+mid, d-mid};
        sort(d0, d0+2);
        if(check(a0, b0, c0, d0))
            hi=mid;
        else
            lo=mid;
    }
    printf("%.15f\n", lo);
    return 0;
}