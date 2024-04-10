#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int a,b,n,g;
int y[1000000],tot;
int q[1000000],tt;

int gcd(int a,int b)
{
    if (!(a%b))
        return b;
    return gcd(b,a%b);
}

void make(int now,int x)
{
    if (now >= tot)
    {
  //      printf("%d\n",x);
        q[tt++] = x;
        return;
    }
    int xx = x;
    while (g%xx == 0)
    {
        make(now+1,xx);
        xx *= y[now];
    }
}

int ffd(int x)
{
    int l = 0,r = tt-1;
    while (l < r)
    {
     //   printf("%d %d\n",l,r);
        int mid = ((l+r)>>1) + 1;
        if (q[mid] > x)
            r = mid-1;
        else
            l = mid;
    }
    return q[l];
}

int main()
{
    scanf("%d%d%d",&a,&b,&n);
    g = gcd(a,b);
    int gg = g;
    int x = 2;
    tot = 0;
    while (g != 1)
    {
        if (g%x == 0) y[tot++] = x;
        while (g%x == 0) g/=x;
        ++x;
    }
    g = gg;
    tt = 0;
    make(0,1);
    sort(q,q+tt);
    //for (int i = 0;i < tt;++i)
    //    printf("%d",q[i]);
    for (int a,b,i = 0;i < n;++i)
    {
        scanf("%d%d",&a,&b);
        if (a > g)
            printf("-1\n");
        else
        {
            int k = ffd(b);
      //          printf("%d\n",k);
            if (k <= b && k >= a)
                printf("%d\n",k);
            else
                printf("-1\n");
        }
    }
    return 0;
}