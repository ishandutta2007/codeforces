#include <iostream>  
#include <stdio.h>  
#include <string.h>  
#include <stack>  
#include <queue>  
#include <map>  
#include <set>  
#include <vector>  
#include <math.h>  
#include <algorithm>  
using namespace std;  
#define ls 2*i  
#define rs 2*i+1  
#define up(i,x,y) for(i=x;i<=y;i++)  
#define down(i,x,y) for(i=x;i>=y;i--)  
#define mem(a,x) memset(a,x,sizeof(a))  
#define w(a) while(a)  
#define LL long long  
const double pi = acos(-1.0);  
#define Len 200005  
#define mod 19999997  
const int INF = 0x3f3f3f3f;  
  
LL n,m,a[Len],b[2*Len],hsh[Len];  
  
int main()  
{  
    LL i,j,k,minn,maxn,ans;  
    bool flag;  
    mem(hsh,0);  
    scanf("%I64d",&n);  
    up(i,1,n)  
    scanf("%I64d",&a[i]);  
    scanf("%I64d",&m);  
    minn = INF,maxn = 0;  
    up(i,1,m)  
    {  
        scanf("%I64d",&b[i]);  
        hsh[b[i]]++;  
        if(b[i]==1 || b[i]==n)  
            hsh[b[i]]++;  
    }  
    up(i,1,n)  
    {  
        minn = min(minn,hsh[i]);  
        maxn = max(maxn,hsh[i]);  
    }  
    if(minn == maxn)  
    {  
        flag = true;  
        up(i,1,n-2)  
        {  
            if(a[i+1]-a[i]!=a[i+2]-a[i+1])  
            {  
                flag = false;  
                break;  
            }  
        }  
        if(!flag)  
            printf("-1\n");  
        else  
            printf("%I64d\n",(a[n]-a[1])*minn-(a[2]-a[1]));  
    }  
    else  
    {  
        LL ans = 0;  
        up(i,1,n-1)  
        {  
            ans+=(a[i+1]-a[i])*min(hsh[i+1],hsh[i]);  
        }  
        printf("%I64d\n",ans);  
    }  
  
    return 0;  
}