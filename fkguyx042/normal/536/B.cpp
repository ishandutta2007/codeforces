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
#define Len 1000006  
#define mod 1000000007  
const int INF = 0x3f3f3f3f;  
  
LL n,m,next[Len],ans,a[Len],len;  
char str[Len];  
bool hsh[Len];  
  
void get_next()  
{  
    LL k = -1,j = 0;  
    next[0] = -1;  
    w(j<len)  
    {  
        if(k == -1 || str[k] == str[j])  
        {  
            j++;  
            k++;  
            next[j] = k;  
        }  
        else  
        {  
            k = next[k];  
        }  
    }  
}  
  
void dfs(LL k)  
{  
    if(k==0) return;  
    hsh[len-k+1] = true;  
    dfs(next[k]);  
}  
  
LL solve(LL k)  
{  
    int i;  
    if(k < 0) return 0;  
    LL ret = 1;  
    up(i,1,k)  
    ret = (ret*26)%mod;  
    return ret;  
}  
  
int main()  
{  
    LL i,j,k,flag;  
    scanf("%I64d%I64d",&n,&m);  
    {  
        flag = 1;  
        scanf("%s",str);  
        len = strlen(str);  
        get_next();//next  
        dfs(next[len]);//  
        ans = 1;  
        if(m==0)//26  
        {  
            printf("%I64d\n",solve(n));  
  
        }  
        else  
        {  
            scanf("%I64d",&a[1]);  
            ans = solve(a[1]-1);//a[1]26  
            up(i,2,m)  
            {  
                scanf("%I64d",&a[i]);  
                if(a[i]-a[i-1]<len)//str  
                {  
                    if(!hsh[a[i]-a[i-1]+1])  
                    {  
                        flag = 0;  
                        printf("0\n");  
                        break;  
                    }  
                }  
                else//lenstr26  
                    ans = (ans*solve(a[i]-a[i-1]-len))%mod;  
            }  
            if(flag)//26  
                printf("%I64d\n",ans*solve(n-a[m]-len+1)%mod);  
        }  
    }  
  
    return 0;  
}