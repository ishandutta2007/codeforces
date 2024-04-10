#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;
#define MOD 1000000007LL
#define B1 97LL
#define B2 47LL
#define MOD1 1000000007LL
#define MOD2 1000000009LL

char s[210001];
char t[210001];
int n,m;
pair<Int,Int> HT;
int occur[210001];
int occurps[210001];
Int B1P,B2P;

void FindOccurances()
{
    int i;
    pair<Int,Int> H;

    memset(occur,0,sizeof(occur));
    H.first=0;
    H.second=0;

    for (i=1;i<=m;i++)
    {
        H.first=(H.first*B1+s[i])%MOD1;
        H.second=(H.second*B2+s[i])%MOD2;
    }

    if (H.first==HT.first && H.second==HT.second)
    {
        occur[1]=1;
    }

    for (i=m+1;i<=n;i++)
    {
        H.first=(H.first*B1+s[i])%MOD1;
        H.second=(H.second*B2+s[i])%MOD2;

        H.first=(H.first-(s[i-m]*B1P)%MOD1+MOD1)%MOD1;
        H.second=(H.second-(s[i-m]*B2P)%MOD2+MOD2)%MOD2;

        if (H.first==HT.first && H.second==HT.second)
        {
            occur[i-m+1]=1;
        }
    }

    occurps[0]=0;

    for (i=1;i<=n;i++)
    {
        occurps[i]=occurps[i-1]+occur[i];
    }

    return;
}

Int F[210001];
Int FSum[210001];
Int FSumSum[210001];
Int NonEmptySum[210001];

int GetSum(int l,int r)
{
    if (l>r)
    return 0;

    return occurps[r]-occurps[l-1];
}

bool IS(int l,int r)
{
    int R=r-m+1;

    if (GetSum(l,R)>0)
    return true;
    else
    return false;
}

int main()
{
    int i;
    int l,r,mid,best;

    scanf("%s",s+1);
    n=strlen(s+1);

    scanf("%s",t+1);
    m=strlen(t+1);

    B1P=1;
    B2P=1;

    for (i=1;i<=m;i++)
    {
        B1P*=B1;
        B1P%=MOD1;

        B2P*=B2;
        B2P%=MOD2;
    }

    HT.first=0;
    HT.second=0;

    for (i=1;i<=m;i++)
    {
        HT.first=( HT.first*B1+t[i] )%MOD1;
        HT.second=( HT.second*B2+t[i] )%MOD2;
    }

    FindOccurances();

    F[0]=0;
    FSum[0]=0;
    FSumSum[0]=0;

    for (i=1;i<=n;i++)
    {
        l=1;
        r=i;
        best=-1;

        while(l<=r)
        {
            mid=(l+r)/2;

            if ( IS(mid,i) )
            {
                l=mid+1;
                best=mid;
            }
            else
            {
                r=mid-1;
            }
        }

        if (best==-1)
        F[i]=0;
        else
        F[i]=FSumSum[best-1]+best;

        ///cout<<"For "<<i<<" we get "<<F[i]<<endl;

        FSum[i]=FSum[i-1]+F[i];

        if (FSum[i]>=MOD)
        FSum[i]-=MOD;

        FSumSum[i]=FSumSum[i-1]+FSum[i];

        if (FSumSum[i]>=MOD)
        FSumSum[i]-=MOD;

        ///cout<<"FSum["<<i<<"]="<<FSum[i]<<endl;
    }

    printf("%lld\n",FSum[n]);

    return 0;
}