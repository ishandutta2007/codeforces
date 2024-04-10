#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int IT[26][524288];
Int ctr[26];
const Int LEAFOFFSET=262143;
char inp[101];
Int L;
Int n,k;

bool NotRemoved(Int c,Int p)
{
    return IT[c][p+LEAFOFFSET]==0;
}

void Kill(Int c,Int ver)
{
    Int rver=ver+LEAFOFFSET;
    Int ind=rver/2;

    IT[c][rver]=1;

    while(ind>0)
    {
        IT[c][ind]=IT[c][2*ind]+IT[c][2*ind+1];

        ind/=2;
    }

    return;
}

Int GetSum(Int c,Int p)
{
    Int sum=IT[c][p+LEAFOFFSET];
    Int ind=p+LEAFOFFSET;

    while(ind>1)
    {
        if (ind%2==1)
        {
            sum=sum+IT[c][ind-1];
        }

        ind/=2;
    }

    return sum;
}

void Remove(Int c,Int p)
{
    Int l,r,mid,best;
    Int curpos;

    l=1;
    r=LEAFOFFSET+1;

    ///cout<<"Removing the "<<p<<"-th from tree of characters "<<(char)(c+'a')<<endl;

    while(l<=r)
    {
        mid=(l+r)/2;

        curpos=mid-GetSum(c,mid);

        if (curpos<p)
        {
            l=mid+1;
        }
        else if (curpos>p)
        {
            r=mid-1;
        }
        else
        {
            if (NotRemoved(c,mid))
            {
                best=mid;
            }

            r=mid-1;
        }
    }

    Kill(c,best);

    return;
}

int main()
{
    Int i,j;
    Int p;
    char c;
    Int C;

    memset(IT,0,sizeof(IT[0][0])*26*(LEAFOFFSET*2+2));
    memset(ctr,0,sizeof(ctr));

    scanf("%I64d",&k);
    scanf("%s",inp);
    L=strlen(inp);

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&p);

        scanf("%c",&c);

        while(c<'a' || c>'z')
        {
            scanf("%c",&c);
        }

        C=c-'a';

        Remove(C,p);
    }

    /**for (i=0;i<=2;i++)
    {
        cout<<"Tree of characters "<<(char)(i+'a')<<" looks as follows:"<<endl;
        for (j=1;j<=5;j++)
        {
            cout<<IT[i][j+LEAFOFFSET]<<" ";
        }
        cout<<endl<<endl;
    }**/

    for (i=1;i<=k;i++)
    {
        for (j=0;j<L;j++)
        {
            C=inp[j]-'a';
            ctr[C]++;

            if (NotRemoved(C,ctr[C]))
            {
                printf("%c",inp[j]);
            }
        }
    }

    printf("\n");

    return 0;
}