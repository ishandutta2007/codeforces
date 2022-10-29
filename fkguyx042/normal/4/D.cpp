#include <set>  
#include <map>  
#include <queue>  
#include <math.h>  
#include <vector>  
#include <string>  
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <iostream>  
#include <cctype>  
#include <algorithm>  
  
#define eps 1e-10  
#define pi acos(-1.0)  
#define inf 107374182  
#define inf64 1152921504606846976  
#define lc l,m,tr<<1  
#define rc m + 1,r,tr<<1|1  
#define zero(a) fabs(a)<eps  
#define iabs(x)  ((x) > 0 ? (x) : -(x))  
#define clear1(A, X, SIZE) memset(A, X, sizeof(A[0]) * (min(SIZE,sizeof(A))))  
#define clearall(A, X) memset(A, X, sizeof(A))  
#define memcopy1(A , X, SIZE) memcpy(A , X ,sizeof(X[0])*(SIZE))  
#define memcopyall(A, X) memcpy(A , X ,sizeof(X))  
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )  
#define min( x, y )  ( ((x) < (y)) ? (x) : (y) )  
  
using namespace std;  
  
struct node  
{  
    int w,h,num;  
    bool operator <(const node a)const  
    {  
        if(w+h==a.w+a.h)  
        {  
            if(w==a.w)return h<a.h;  
            else return w<a.w;  
        }  
        return w+h<a.w+a.h;  
    }  
} envelopes[5000];  
  
int cnt;  
int dp[5005],pre[5005];  
void output(int num)  
{  
    if(pre[num]!=-1)output(pre[num]);  
    printf("%d ",envelopes[num].num);  
    return ;  
}  
int main()  
{  
    int n,w,h;  
    cnt=0;  
    scanf("%d%d%d",&n,&w,&h);  
    for(int i=0; i<n; i++)  
    {  
        scanf("%d%d",&envelopes[cnt].w,&envelopes[cnt].h);  
        envelopes[cnt].num=i+1;  
        if(envelopes[cnt].w>w&&envelopes[cnt].h>h)cnt++;  
    }  
    if(cnt==0)  
    {  
        puts("0");  
        return 0;  
    }  
    clearall(pre,-1);  
    sort(envelopes,envelopes+cnt);  
    int maxnum=1,maxp=0;  
    dp[0]=1;  
    for(int i=1; i<cnt; i++)  
    {  
        int max1=-1,mp=-1;  
        for(int j=i-1; j>=0; j--)  
        {  
            if(envelopes[j].w<envelopes[i].w&&envelopes[j].h<envelopes[i].h&&max1<dp[j])  
            {  
                max1=dp[j];  
                mp=j;  
            }  
        }  
        dp[i]=max1+1;  
        pre[i]=mp;  
        if(dp[i]>maxnum)  
        {  
            maxnum=dp[i];  
            maxp=i;  
        }  
    }  
    printf("%d\n",maxnum);  
    output(maxp);  
    return 0;  
}