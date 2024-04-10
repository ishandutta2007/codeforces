#include<string.h>  
#include<stdio.h>  
#define LL __int64  
LL w,m;  
int main()  
{  
    scanf("%I64d%I64d",&w,&m);  
    if(w<=3)  
    {  
        printf("YES\n");  
        return 0;  
    }  
    while(m)  
    {  
        if(!((m-1)%w)) m--;  
        else if(!((m+1)%w)) m++;  
        else if(m%w) {printf("NO\n");return 0;}  
        m=m/w;  
    }  
    printf("YES\n");  
    return 0;  
}