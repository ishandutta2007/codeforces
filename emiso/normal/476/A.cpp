//EM NOME DE ABELLA
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    float n,m,b,p;
    scanf("%f %f",&n,&m);
    b = ceil(n/2);
    if(m>n) puts("-1");
    else
    {
        p=m;
        while(p<b)
        {
                  p+=m;
        }
        printf("%.0f\n",p);
    }
    return 0;
}