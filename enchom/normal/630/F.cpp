#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef unsigned long long Int;

bool marked[1011];

Int C(Int k,Int n)
{
    Int ans=1;
    int i,j;

    memset(marked,false,sizeof(marked));

    for (i=n-k+1;i<=n;i++)
    {
        ans*=(Int)i;

        for (j=1;j<=k;j++)
        {
            if (!marked[j])
            {
                if (ans%(Int)j==0)
                {
                    ans/=(Int)j;
                    marked[j]=true;
                }
            }
        }
    }

    return ans;
}

void EnchomSolve()
{
    Int n;
    Int ans;

    cin>>n;

    ans=C(5,n)+C(6,n)+C(7,n);

    cout<<ans<<endl;

    return;
}

int main()
{
    EnchomSolve();
    return 0;
}