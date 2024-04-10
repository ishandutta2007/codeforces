#include<bits/stdc++.h>
#define maxn 1000005

using namespace std;
typedef long long ll;

ll s[maxn],t[maxn],a[maxn],b[maxn];
ll p,q,n,m,k,cnt[maxn],w,x,y,xx,yy,r;

int main()
{
    scanf("%I64d%I64d%I64d",&n,&k,&m);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    if (k>n){
        bool f=true;
        for (int i=1;i<n;i++) if (a[i]!=a[0]) f=false;
        if (f) printf("%I64d\n",n*m%k);
        else printf("%I64d\n",n*m);
        return 0;
    }
    w=1; cnt[1]=1; b[0]=a[0];
    for (int i=1;i<n;i++)
    {
        b[w++]=a[i];
        if ((w>1)&&b[w-2]==b[w-1]) cnt[w]=cnt[w-1]+1; else cnt[w]=1;
        if (cnt[w]==k) w-=k;
    }
    p=0;q=0;
    x=0;y=w-1;
    while (b[x]==b[y])
    {
        xx=x+1; while (xx<=y&&b[xx]==b[x]) xx++;
        yy=y-1; while (yy>=x&&b[yy]==b[y]) yy--;
        if (xx>yy){
            r=m*(y-x+1);
            for (int i=0;i<r%k;i++) t[q++]=b[x];

                while (p>0&&q>0&&s[p-1]==t[q-1]){
                    xx=p-1;yy=q-1;
                    while (xx>0&&s[xx-1]==s[p-1]) xx--;
                    while (yy>0&&t[yy-1]==t[q-1]) yy--;
                    if (p+q-xx-yy>=k){
                        q=p+q-xx-k;
                        p=xx;
                    }
                    else break;
                }
                printf("%I64d\n",p+q);
                return 0;
        }
        else if (xx-x+y-yy>=k) {
            yy=y+xx-x-k;
            for (int i=x;i<xx;i++) s[p++]=b[i];
            for (int i=y;i>yy;i--) t[q++]=b[i];
            x=xx;y=yy;
        }
        else break;
    }
    printf("%I64d\n",m*(y-x+1)+p+q);
    return 0;
}