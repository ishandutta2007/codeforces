#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<cstdlib>  
#include <cstring>  
using namespace std;  
  
int main()  
{  
    int i, n, a, b, c, d;  
    scanf("%d", &n);  
    for (i = 0; i<4; i++)  
    {  
        scanf("%d %d %d %d", &a, &b, &c, &d);  
        if (a>b)  
        {  
            a = b;  
        }  
        if (c > d)  
        {  
            c = d;  
        }  
        if (a + c <= n)   
        {  
            printf("%d %d %d", i + 1, a, n - a);   
            return 0;   
        }  
    }  
    printf("-1");  
    return 0;  
}