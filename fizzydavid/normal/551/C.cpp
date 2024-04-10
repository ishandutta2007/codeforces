#include<bits/stdc++.h>
#define R() for(int i=1;i<=N;i++)
int N,M,a[100111];
long long S,t,l,r=1ll<<50,m;
int main()
{
    scanf("%d%d",&N,&M);
    R()scanf("%d",&a[i]);
    while(l<=r)
    {
        m=l+r>>1;
        S=0;t=0;
        R()
        {
            S+=a[i];
            if(m-i<=0)
            {
                if(S!=0)
                {
                    t+=M;break;
                }else continue;
            }
            t+=S/(m-i),S-=S/(m-i)*(m-i);
        }
        t+=(S>0);
        if(t>M)l=m+1;else r=m-1;
    }
    printf("%I64d",l);
}