#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

int main()
{
    Int n, k, l, c, d, p, nl, np;
    Int drink;
    Int limes;
    Int salt;
    Int smallest=999999999;
    
    scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d",&n,&k,&l,&c,&d,&p,&nl,&np);
    
    drink=l*k;
    limes=c*d;
    salt=p;
    
    if (drink/nl<smallest)
    smallest=drink/nl;
    
    if (limes<smallest)
    smallest=limes;
    
    if (salt/np<smallest)
    smallest=salt/np;
    
    smallest=smallest/n;
    
    printf("%I64d\n",smallest);
    
    return 0;
}