#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
double x[200];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lf",&x[i]);
    sort(x+1,x+1+n,greater<double>());
    double p=1,s=0;
    for (int i=1;i<=n;i++)
    if (s<1)
    if (x[i]<1)
    {
        p*=(1-x[i]);
        s+=x[i]/(1-x[i]);
    }
    else p=s=1;
    printf("%.9lf\n",p*s);
    return 0;
}