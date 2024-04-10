#include <stdio.h>
#include <string.h>

int a,b,c;

int make(int x)
{
    int l = 0,a = 0;
    char p[32] = {0};
    int t = x;
    while (t)
    {
        p[l++] = t%10;
        t /= 10;
    }
    int pp = 1;
    for (int i = 0;i < l;++i)
    {
        if (p[i])
        {
            a = a  + p[i] * pp;
        pp *= 10;
        }
    }
    return a;
}

int main()
{
    scanf("%d%d",&a,&b);
    c = a+b;
  //  printf("%d\n",make(a));
    if (make(a) + make(b) == make(c))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}