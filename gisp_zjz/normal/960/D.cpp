#include<bits/stdc++.h>
#define maxn 64

using namespace std;
typedef long long ll;
ll a[maxn],b[maxn],o,n,k,m,query,r,d;

int main()
{
    scanf("%d",&query);
    b[0]=1; for (int i=1;i<=63;i++) b[i]=b[i-1]*2;
    while (query--)
    {
        scanf("%d%lld",&o,&m);
        k=m; r=0; while (k>1) r++,k/=2;
        if (o<3){
            scanf("%lld",&d);
            a[r]=((a[r]+d)%b[r]+b[r])%b[r];
            if (o==1) a[r+1]=((a[r+1]+b[r+1]-d*2)%b[r+1]+b[r+1])%b[r+1];
        }
        else {
            while (m){
                printf("%lld ",m);
                m=((m+a[r])%b[r]+b[r])/2;
                r--;
            }
            printf("\n");
        }
    }
    return 0;
}