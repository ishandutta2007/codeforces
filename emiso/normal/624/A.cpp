#include <stdio.h>

int main()
{
    double d,L,v1,v2;
    scanf("%lf %lf %lf %lf",&d,&L,&v1,&v2);
    printf("%.6f\n",(L - d)/(v1+v2));
    return 0;
}