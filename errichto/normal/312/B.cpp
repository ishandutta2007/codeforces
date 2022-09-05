#include<cstdio>
int main()
{
    double a,b,c,d;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    return !printf("%lf",a*d/(  a*d+c*(b-a) ));
}