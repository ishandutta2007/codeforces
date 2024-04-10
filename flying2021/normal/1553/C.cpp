#include<iostream>
#include<cstdio>
#include<cstring>
#define N 11
using namespace std;
char s[N];int a[N];
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t --> 0)
    {
        scanf("%s",s);
        int n=strlen(s),res=10;
        for(int i=0;i<1<<n;i++)
        {
            bool can=true;
            for(int j=0;j<n;j++)
                if(s[j]!='?' && ((i>>j)&1)!=(s[j]-'0')) can=false;
            if(!can) continue;
            int c0=5,c1=5,s0=0,s1=0,tt=0;
            for(int j=0;j<n;j++)
            {
                ++tt;
                if(j&1)
                {
                    if(i>>j&1) s1++;
                    else c1--;
                }
                else
                {
                    if(i>>j&1) s0++;
                    else c0--;
                }
                if(s1>c0 || s0>c1) break;
            }
            res=min(res,tt);
        }
        printf("%d\n",res);
    }
    return 0;
}