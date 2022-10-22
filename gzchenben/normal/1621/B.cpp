#include<cstdio>
#include<algorithm>
using namespace std;
int n,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int Minn=2e9,Maxn=0,minP1=2e9,minP2=2e9,minP3=2e9;
        for(int i=1;i<=n;i++)
        {
            int L,R,C;
            scanf("%d%d%d",&L,&R,&C);
            if(L<Minn) 
            {
                minP1=minP3=2e9;
                Minn=L;
            }
            if(R>Maxn)
            {
                minP2=minP3=2e9;
                Maxn=R;
            }
            if(L==Minn) minP1=min(minP1,C);
            if(R==Maxn) minP2=min(minP2,C);
            if(L==Minn && R==Maxn) minP3=min(minP3,C);
            printf("%d\n",min(minP1+minP2,minP3));
        }
    }
}