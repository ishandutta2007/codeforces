#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;
typedef long double Double;

int n;
Int L[11],R[11];

Double Ways=0.0;
Double Sum=0.0;

bool used[11];

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

void MultipleWin(int value,int mask)
{
    int i;
    int ctr=0;
    Double total=1.0;

    for (i=0;i<n;i++)
    {
        if ( ( mask&(1<<i) )>0 )
        {
            used[i+1]=true;
            ctr++;
        }
        else
        used[i+1]=false;

        if (used[i+1])
        {
            if (value>R[i+1] || value<L[i+1])
            return;
        }
    }

    if (ctr<2)
    return;

    for (i=1;i<=n;i++)
    {
        if (!used[i])
        {
            if (L[i]>=value)
            return;

            total=total*(Double)( MIN(value-1,R[i])-L[i]+1 );
        }
    }

    Ways+=total;
    Sum+=total*(Double)(value);

    return;
}

void MultipleWinners()
{
    int mask;
    int i;

    for (i=1;i<=10000;i++)
    {
        ///Multiple wins with i

        for (mask=1;mask<(1<<n);mask++)
        {
            MultipleWin(i,mask);
        }
    }

    return;
}

/// ////////////

void SingleWin(int k,int value,int mask)
{
    int i;
    Double total;

    for (i=0;i<n;i++)
    {
        if ( (mask&(1<<i))>0 )
        used[i+1]=true;
        else
        used[i+1]=false;
    }

    if (used[k])
    return;

    if (R[k]<=value)
    return;

    total=R[k]-MAX(value,L[k]-1);

    for (i=1;i<=n;i++)
    {
        if (used[i])
        {
            if (value<L[i] || value>R[i])
            return;
        }
        else if (i!=k)
        {
            if (L[i]>=value)
            return;

            total=total*(Double)( MIN(value-1,R[i])-L[i]+1 );
        }
    }

    /**
    cout<<k<<" winning but paying "<<value<<" since ";
    for (i=1;i<=n;i++)
    {
        if (used[i])
        cout<<i<<" ";
    }
    cout<<"are paying it"<<endl;

    cout<<total<<" ways"<<endl;
    **/

    Ways+=total;
    Sum+=total*(Double)(value);

    return;
}

void Winner(int k)
{
    int i,mask;

    for (i=1;i<=10000;i++)
    {
        for (mask=1;mask<(1<<n);mask++)
        {
            SingleWin(k,i,mask);
        }
    }

    return;
}

void SingleWinner()
{
    int i;

    for (i=1;i<=5;i++)
    {
        Winner(i);
    }

    return;
}

int main()
{
    int i;
    Double Ans;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&L[i],&R[i]);
    }

    SingleWinner();

    //cout<<Ways<<" "<<Sum<<endl;

    MultipleWinners();

    //cout<<Ways<<" "<<Sum<<endl;

    Ans=Sum/Ways;

    printf("%.10f\n",(double)Ans);

    return 0;
}
/**
3
2 5
3 4
1 6
**/