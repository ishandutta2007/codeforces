#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;
#define MOD1 1000000007LL
#define MOD2 1000000009LL
#define B1 107
#define B2 97
#define OFFSET 2000000000LL

pair<Int,Int> E_Hash;
pair<Int,Int> B_Hash;

int n,w;
int bears[200001];
int elep[200001];

Int ser[200001];
Int pat[200001];

Int B1Pow[200001];
Int B2Pow[200001];

int main()
{
    int i;
    int ans=0;

    scanf("%d %d",&n,&w);

    if (w==1)
    {
        printf("%d\n",n);
        return 0;
    }

    B1Pow[0]=1;
    B2Pow[0]=1;

    for (i=1;i<=n;i++)
    {
        B1Pow[i]=(B1Pow[i-1]*B1)%MOD1;
        B2Pow[i]=(B2Pow[i-1]*B2)%MOD2;
    }

    if (w>n)
    {
        printf("0\n");
        return 0;
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d",&bears[i]);
    }

    for (i=1;i<=w;i++)
    {
        scanf("%d",&elep[i]);
    }

    for (i=2;i<=n;i++)
    {
        ser[i]=bears[i]-bears[i-1]+OFFSET;
    }

    E_Hash=make_pair(0,0);
    for (i=2;i<=w;i++)
    {
        pat[i]=elep[i]-elep[i-1]+OFFSET;

        E_Hash.first=(E_Hash.first*B1 + pat[i])%MOD1;
        E_Hash.second=(E_Hash.second*B2 + pat[i])%MOD2;
    }

    B_Hash=make_pair(0,0);
    for (i=2;i<=w;i++)
    {
        B_Hash.first=(B_Hash.first*B1 + ser[i])%MOD1;
        B_Hash.second=(B_Hash.second*B2 + ser[i])%MOD2;
    }

    if (B_Hash==E_Hash)
    {
        ans++;
    }

    for (i=w+1;i<=n;i++)
    {
        B_Hash.first-=(B1Pow[w-2] * ser[i-w+1])%MOD1;
        if (B_Hash.first<0)
        B_Hash.first+=MOD1;
        B_Hash.first=(B_Hash.first*B1 + ser[i])%MOD1;

        B_Hash.second-=(B2Pow[w-2] * ser[i-w+1])%MOD2;
        if (B_Hash.second<0)
        B_Hash.second+=MOD2;
        B_Hash.second=(B_Hash.second*B2 + ser[i])%MOD2;

        if (B_Hash==E_Hash)
        {
            ans++;
        }
    }

    printf("%d\n",ans);

    return 0;
}