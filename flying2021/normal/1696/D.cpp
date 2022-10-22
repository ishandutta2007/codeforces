#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 1000010
using namespace std;
int a[N],mx[N],mn[N],mxt,mnt,f[N];
int main()
{
    int t;scanf("%d",&t);
    while(t --> 0)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        mx[0]=mn[0]=0,mxt=mnt=0;
        f[0]=0;
        for(int i=1;i<=n;i++)
        {
            while(mxt && a[mx[mxt]]>a[i]) mxt--;
            while(mnt && a[mn[mnt]]<a[i]) mnt--;
            int p=0;
            if(!mxt && !mnt) f[i]=0;
            else
            {
                if(mx[mxt]>mn[mnt]) p=*lower_bound(mx+1,mx+mxt+1,mn[mnt]);
                else p=*lower_bound(mn+1,mn+mnt+1,mx[mxt]);
                f[i]=f[p]+1;
            }
            mx[++mxt]=i,mn[++mnt]=i;
        }
        printf("%d\n",f[n]);
    }
    return 0;
}