#include<cstdio>
using namespace std;
int n,k,t,a[200005],cnt[200005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n+1;i++) cnt[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        int Minn=(n-k+1)/2+k;
        int R=0,ansL=0,ansR=n+1,Now=0;
        for(int L=1;L<=n;L++)
        {
            while(Now<Minn && R!=n+1)   
            {
                R++;
                Now+=cnt[R];
            }
            if(R==n+1) break;
            if(ansR-ansL>R-L)
            {
                ansL=L;
                ansR=R;
            }
            Now-=cnt[L];
        }
        printf("%d %d\n",ansL,ansR);
        int dif=0,par=1,lst=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=ansL && a[i]<=ansR) dif++;
            else dif--;
            if(dif>0 && par<k) 
            {
                printf("%d %d\n",lst+1,i); 
                par++;
                lst=i;
                dif=0;
            }
        }
        printf("%d %d\n",lst+1,n);
    }
}