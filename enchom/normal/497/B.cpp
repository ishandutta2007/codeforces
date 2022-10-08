#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int seq[100011];
int sum1[100011],sum2[100011];
vector< pair<int,int> > Possibles;

vector< pair<int,int> > Ans;

int P[3];
int S[3];

bool Game(int l,int r,int t)
{
    int P1=sum1[r]-sum1[l-1];
    int P2=sum2[r]-sum2[l-1];

    if (P1>=t || P2>=t)
    return true;
    else
    return false;
}


int S1,S2;

int TryT(int t)
{
    int L=1;
    int l,r,mid,best;
    int lastset=0;

    S1=0;
    S2=0;

    while(L!=n+1)
    {
        l=L;
        r=n;
        best=-1;

        while(l<=r)
        {
            mid=(l+r)/2;

            if (Game(L,mid,t))
            {
                best=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        if (best==-1)
        return -1;

        if (sum1[best]-sum1[L-1]>=t)
        {
            S1++;
            lastset=1;
        }
        else
        {
            S2++;
            lastset=2;
        }

        L=best+1;
    }

    if (S1==S2)
    return -1;

    if (S1>S2)
    {
        if (lastset!=1)
        return -1;
        else
        return S1;
    }
    else
    {
        if (lastset!=2)
        return -1;
        else
        return S2;
    }
}

int main()
{
    int i;
    int M;
    int S;

    scanf("%d",&n);

    sum1[0]=0;
    sum2[0]=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&seq[i]);

        sum1[i]=sum1[i-1];
        sum2[i]=sum2[i-1];

        if (seq[i]==1)
        sum1[i]++;
        else
        sum2[i]++;
    }

    for (i=1;i<=n;i++)
    {
        S=TryT(i);

        if (S!=-1)
        {
            Ans.push_back(make_pair(S,i));
        }
    }

    sort(Ans.begin(),Ans.end());

    printf("%d\n",(int)Ans.size());

    for (i=0;i<Ans.size();i++)
    {
        printf("%d %d\n",Ans[i].first,Ans[i].second);
    }

    return 0;
}