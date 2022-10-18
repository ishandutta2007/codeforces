#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int gcd(int a,int b) {return b==0 ? a : gcd(b,a%b);};

int val[100004]={0};
int res[100004]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a,b,kol[10]={0};
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val[i]);
        kol[val[i]]++;
    }
    if (a<b)
    {
        int my[10]={0};
        for(int i=5;i>=1;i--)
        {
            if (a>0)
            {
                my[i]=min(a,kol[i]);
                a-=my[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            if (my[val[i]]>0)
            {
                my[val[i]]--;
                res[i]=1;
            } else res[i]=2;
        }
    }
    else
    if (a>b)
    {
        int my[10]={0};
        for(int i=5;i>=1;i--)
        {
            if (b>0)
            {
                my[i]=min(b,kol[i]);
                b-=my[i];
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if (my[val[i]]>0)
            {
                my[val[i]]--;
                res[i]=2;
            } else res[i]=1;
        }
    }
    else
        if (a==b)
        {
            for(int i=0;i<n;i++)
                if (i<a) res[i]=1;
                else res[i]=2;
        }
    printf("%d",res[0]);
    for(int i=1;i<n;i++)
        printf(" %d",res[i]);
    printf("\n");
    return 0;
}