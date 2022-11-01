#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int v=-1;
    if(v<a+b+c) v = a+b+c;
    if(v<(a*b)+c) v = (a*b)+c;
    if(v< (a+b)*c) v = (a+b)*c;
    if(v< a*b*c) v = a*b*c;
    if(v< a+(b*c)) v = a+(b*c);
    if(v<a*(b+c)) v = a*(b+c);
    printf("%d\n",v);
    return 0;
}