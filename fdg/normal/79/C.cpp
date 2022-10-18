#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <set>
#include <cstdio>
#include <cstring>
#include <ctime>

#define ll long long

using namespace std;

char str[11][11]={0};
char mas[100005]={0};
int dp[100005]={0};
int pos[100005]={0};

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    int n,len[11]={0};
    scanf("%s\n",mas);
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        cin >> str[i];
        len[i]=strlen(str[i]);
    }
    dp[0]=1; pos[0]=0;
    for(int i=0;i<n;i++)
    {
        if (len[i]==1&&mas[0]==str[i][0]) dp[0]=0,pos[0]=1;
    }
    int l=strlen(mas);
    for(int i=1;i<l;i++)
    {
        dp[i]=dp[i-1]+1;
        pos[i]=pos[i-1];
        int rpos=-1;
        for(int j=0;j<n;j++)
        {
            if (len[j]>i+1) continue;
            bool ok=true;
            for(int t=0;t<len[j];t++)
                if (mas[i-t]!=str[j][len[j]-1-t])
                {
                    ok=false;
                    break;
                }
            if (ok) rpos=max(rpos,i-len[j]+2);
        }
        if (rpos!=-1)
        {
            if (i-rpos+1<=dp[i]) dp[i]=i-rpos+1,pos[i]=rpos;
        }
    }
    int mx=0;
    for(int i=0;i<l;i++)
        if (dp[i]>mx) mx=dp[i];
    if (mx==0) printf("0 0\n");
    else
    {
        for(int i=0;i<l;i++)
            if (dp[i]==mx)
            {
                printf("%d %d\n",dp[i],pos[i]);
                return 0;
            }
    }
    return 0;
}