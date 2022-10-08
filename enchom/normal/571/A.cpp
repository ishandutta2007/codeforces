#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int Solve(int a,int b,int c,int inc)
{
    int A=a,B=b+c;
    int l,r,mid,best;
    Int answer;
    Int n;

    l=0;
    r=inc;
    best=-1;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (A+mid>=B+(inc-mid))
        {
            best=mid;
            r=mid-1;
        }
        else
        l=mid+1;
    }

    if (best==-1)
    return 0;

    n=inc-best+1;
    answer=( n*(n+1LL) )/2LL;

    return answer;
}

Int F[300111][5];

Int Batrak(int val,int pile)
{
    if (pile==4 || val==0)
    return 1;
    if (F[val][pile]!=-1)
    return F[val][pile];

    F[val][pile]=Batrak(val-1,pile)+Batrak(val,pile+1);

    return F[val][pile];
}

int main()
{
    int a,b,c,l;
    int i;
    Int ans=0;
    Int total;

    scanf("%d %d %d %d",&a,&b,&c,&l);

    memset(F,-1,sizeof(F));

    total=Batrak(l,1);

    for (i=0;i<=l;i++)
    {
        //cout<<i<<" --- "<<Solve(a,b,c,i)<<" "<<Solve(b,a,c,i)<<" "<<Solve(c,a,b,i)<<endl;
        ans+=Solve(a,b,c,i)+Solve(b,a,c,i)+Solve(c,a,b,i);
    }

    //cout<<total<<" "<<ans<<endl;
    printf("%lld\n",total-ans);

    return 0;
}