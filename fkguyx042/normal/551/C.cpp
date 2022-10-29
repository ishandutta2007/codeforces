#include<algorithm>
#include<cstdio>  
#include<cstring>
using namespace std;  
#define LL long long  
#define N 100005   
const int mod = 1e9+7;  
int n,m,tot;  
LL a[N];  
int check(LL x)  
{  
    int cnt=m;  
    int i;  
    LL s=0;  
    for(i = 1; i<=tot; i++)  
    {  
        s+=a[i];  
        while(s+i>=x)
        {  
            s-=x-i;
            cnt--;  
            if(cnt<0) return 0;  
        }  
    }  
    if(cnt==0) return s<=0;  
    return 1;  
}  
int main()  
{  
  int i;
    LL ans,sum,l,r;  
    while(~scanf("%d%d",&n,&m))  
    {  
        sum = 0;  
        for(i = 1; i<=n; i++)  
        {  
            scanf("%I64d",&a[i]);  
            sum+=a[i];  
            if(a[i])  
                tot = i;  
        }  
        l = tot,r = tot+sum;  
        while(l<=r)  
        {  
            LL mid = (l+r)>>1;  
            if(check(mid))  
            {  
                ans = mid;  
                r = mid-1;  
            }  
            else  
                l = mid+1;  
        }  
        printf("%I64d\n",ans);  
    }  
  
    return 0;  
}