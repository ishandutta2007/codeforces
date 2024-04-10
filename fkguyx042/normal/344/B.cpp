#include <iostream>  
#include<algorithm>  
#include<cstdio>  
#include<cmath>  
#include<cstring>  
#include<cstdlib>  
using namespace std;  
  
int main()  
{  
    int a,b,c;  
    int x,y,z;  
    scanf("%d%d%d",&a,&b,&c);  
    x=b+a-c;  
    y=b+c-a;  
    z=a+c-b;  
    if(x<0 || y<0 || z<0 || x%2 || y%2 || z%2)  
    {  
        printf("Impossible\n");  
    }  
    else  
    {  
        printf("%d %d %d\n",x/2,y/2,z/2);  
    }  
    return 0;  
}