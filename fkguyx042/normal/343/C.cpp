#include <cstdio>  
#include <iostream>  
#include <cmath>  
#include <algorithm>  
#include <cstring>  
using namespace std;  
#define maxn 100010  
int m,n;  
long long h[maxn],p[maxn];  
const long long inf = 200000000010LL;  
bool ok(long long mid)  
{  
    int cnt,tmp=1;  
    for(cnt=1;cnt<=n;cnt++)  
    {    
        if(h[cnt]+mid<p[tmp])  
            continue;  
        if(h[cnt]-mid>p[tmp])  
            return false;  
        long long pp=max(p[tmp]+mid-abs(h[cnt]-p[tmp]),h[cnt]+(mid-abs(h[cnt]-p[tmp]))/2);  
        while(p[tmp]<=pp && tmp<=m)  
            tmp++;  
        if(tmp==m+1)  
        return true;  
    }  
    return false;  
}  
int main()  
{  
    while(cin>>n>>m)  
    {  
        for(int i=1;i<=n;i++)  
            cin>>h[i];  
        for(int i=1;i<=m;i++)  
            cin>>p[i];  
        long long l=0,r=inf,mid,ans;  
        int cas=1000;  
        while(l<r && cas--)  
        {  
            mid=(l+r)/2;  
            if(ok(mid))  
            {  
                ans=mid;  
                r=mid;  
            }  
            else  
                l=mid+1;  
        }  
        cout<<ans<<endl;  
    }  
    return 0;  
}