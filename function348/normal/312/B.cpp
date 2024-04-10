#include<cstdio>
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%lf\n",(double)a*d/(b*c+a*d-a*c));
}