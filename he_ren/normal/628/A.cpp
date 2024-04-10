#include<cstdio>

int main(void)
{
    int n,b,p;
    scanf("%d%d%d",&n,&b,&p);
    printf("%d %d",(n-1)*(2*b+1),n*p);
    return 0;
}