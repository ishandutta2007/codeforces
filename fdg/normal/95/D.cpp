#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

int dp[2][1005][2005],mod=1000000007,T,k;
int ten[1002],good[1002];

int calc(char * str)
{
    int l=strlen(str),ret=0,lastH=-2000;
    bool ok=false;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<str[i]-'0';j++)
        {
            if (j==4||j==7)
            {
                bool nok=((i-lastH)<=k);
                if (nok) ret=(ret+((l-i-1>=0) ? ten[l-i-1] : 0))%mod;
                else
                {
                    ret=((ret+dp[0][l-i-1][min(k,l-i-1)+1000])%mod+good[l-i-1])%mod;
                }
            }
            else ret=((ret+(k-(i-lastH)>=0 ? dp[0][l-i-1][min(k-(i-lastH),l-i-1)+1000] : 0))%mod+good[l-i-1])%mod;
        }
        if (str[i]=='4'||str[i]=='7')
        {
            if (i-lastH<=k)
            {
                int tmp=0;
                for(i=i+1;i<l;i++)
                    tmp=(10LL*tmp+str[i]-'0')%mod;
                ret=(ret+tmp+1)%mod;
                return ret;
                ok=true;
            }
            lastH=i;
        }
    }
    return ret;
}

bool isHappy(char * str)
{
    int lastH=-2000,l=strlen(str);
    for(int i=0;i<l;i++)
    {
        if (str[i]=='4'||str[i]=='7')
        {
            if (i-lastH<=k) return true;
            lastH=i;
        }
    }
    return false;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d%d\n",&T,&k);
    for(int i=0;i<10;i++)
    {
        if (i==4||i==7) dp[0][1][1001]++;
        else dp[0][1][0]++;
    }
    for(int len=1;len<=1000;len++)
    {
        for(int w=0;w<2;w++)
        {
            for(int last=0;last<=len+1000;last++)
            {
                if (dp[w][len][last]!=0)
                {
                    for(int i=0;i<10;i++)
                    {
                        if (i==4||i==7)
                        {
                            bool nw=(((len+1001)-last)<=k)|w;
                            dp[nw][len+1][len+1001]=(dp[nw][len+1][len+1001]+dp[w][len][last])%mod;
                        }
                        else
                            dp[w][len+1][last]=(dp[w][len+1][last]+dp[w][len][last])%mod;
                    }
                }
            }
        }
    }
    ten[0]=1;
    for(int i=1;i<=1000;i++)
        ten[i]=(10LL*ten[i-1])%mod;
    good[0]=0;
    for(int len=1;len<=1000;len++)
        for(int last=1001;last<=len+1000;last++)
            good[len]=(good[len]+dp[1][len][last])%mod;
    for(int len=1;len<=1000;len++)
    {
        int l=1001,r=len+1000;
        while(l<r)
        {
            swap(dp[0][len][l],dp[0][len][r]);
            l++; r--;
        }
    }
    for(int len=1;len<=1000;len++)
        for(int last=1002;last<=len+1000;last++)
            dp[0][len][last]=(dp[0][len][last]+dp[0][len][last-1])%mod;
    char str[2002]={0};
    while(T--)
    {
        scanf("%s ",str);
        int res=mod-calc(str);
        if (isHappy(str)) res=(res+1)%mod;
        scanf("%s\n",str);
        res=(res+calc(str))%mod;
        printf("%d\n",res);
    }
    return 0;
}