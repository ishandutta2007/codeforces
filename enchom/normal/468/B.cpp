#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,a,b;
pair<int,int> oar[100002];
int p[100002];
int LinkA[100002];
int LinkB[100002];
int Assigned[100002];
int ans[100002];

int Exists(int val)
{
    int l,r,mid;

    l=1;
    r=n;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (p[mid]<val)
        {
            l=mid+1;
        }
        else if (p[mid]>val)
        {
            r=mid-1;
        }
        else
        return mid;
    }

    return 0;
}

bool AssignA(int ver)
{
    if (ver==0)
    return true;

    if (Assigned[ver]==0)
    return true;
    if (Assigned[ver]==1)
    return false;

    Assigned[ver]=0;

    if (!AssignA(LinkA[ver]) || !AssignA(LinkB[ver]))
    return false;
    else
    return true;
}

bool AssignB(int ver)
{
    if (ver==0)
    return true;

    if (Assigned[ver]==1)
    return true;
    if (Assigned[ver]==0)
    return false;

    Assigned[ver]=1;

    if (!AssignB(LinkA[ver]) || !AssignB(LinkB[ver]))
    return false;
    else
    return true;
}

int main()
{
    //freopen("test.txt","r",stdin);

    int i;
    int A,B;

    scanf("%d %d %d",&n,&a,&b);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&oar[i].first);
        oar[i].second=i;
    }

    sort(oar+1,oar+1+n);

    for (i=1;i<=n;i++)
    {
        p[i]=oar[i].first;
    }

    p[0]=-1;

    for (i=1;i<=n;i++)
    {
        A=a-p[i];
        B=b-p[i];

        LinkA[i]=Exists(A);
        //cout<<"LinkA of "<<p[i]<<" is "<<p[ LinkA[i] ]<<endl;

        LinkB[i]=Exists(B);
        //cout<<"LinkB of "<<p[i]<<" is "<<p[ LinkB[i] ]<<endl;
    }

    memset(Assigned,-1,sizeof(Assigned));

    for (i=1;i<=n;i++)
    {
        if (LinkA[i]==0 && LinkB[i]==0)
        {
            printf("NO\n");
            return 0;
        }
        else if (LinkB[i]==0)
        {
            if (!AssignA(i))
            {
                printf("NO\n");
                return 0;
            }
        }
        else if (LinkA[i]==0)
        {
            if (!AssignB(i))
            {
                printf("NO\n");
                return 0;
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        if (Assigned[i]==-1)
        Assigned[i]=0;

        ans[ oar[i].second ]=Assigned[i];
    }

    printf("YES\n");
    for (i=1;i<=n;i++)
    {
        printf("%d",ans[i]);

        if (i!=n)
        printf(" ");
    }
    printf("\n");

    return 0;
}