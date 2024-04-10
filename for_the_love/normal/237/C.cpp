#include <cstdio>
#include <cstring>
const int maxn=1000001;
int i,j,a,b,k,l,r,mid;
int s[maxn],v[maxn];
int check(int limit)
{
        int x;
        for (x=a;x<=b-limit+1;x++)
        {
                if (s[x+limit-1]-s[x-1]<k) return 0;
        }
        return 1;
}
int main()
{
        for (i=2;i<maxn;i++)
        if (!v[i])
        for (j=2;j*i<maxn;j++) v[j*i]=1;
        s[1]=0;
        for (i=2;i<maxn;i++)
        if (!v[i]) s[i]=s[i-1]+1; else s[i]=s[i-1];
        scanf("%d%d%d",&a,&b,&k);
        l=0; r=b-a+1;
        while (l!=r&&l!=r-1)
        {
                mid=(l+r)/2;
                if (check(mid)) r=mid; else l=mid;
        }
        if (!check(b-a+1)) printf("-1\n");
        else
        {
                if (check(l)) printf("%d\n",l); else printf("%d\n",r);
        }
        return 0;
}