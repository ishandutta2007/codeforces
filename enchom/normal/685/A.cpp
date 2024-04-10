#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;
int n,m;
int c1,c2;

int clock[111];
bool used[8];
int ans=0;

bool Okay()
{
    int i;
    Int hr=0,mn=0;

    for (i=c1;i>=1;i--)
    {
        hr*=7LL;
        hr+=(Int)clock[i];
    }

    for (i=c1+c2;i>c1;i--)
    {
        mn*=7LL;
        mn+=(Int)clock[i];
    }


    if (hr>=(Int)n || mn>=(Int)m)
    return false;

    /*for (i=1;i<=c1+c2;i++)
    {
        cout<<clock[i]<<" ";
    }
    cout<<endl;
    cout<<"="<<hr<<" : "<<mn<<endl<<endl;*/

    return true;
}

void Batrak(int ind)
{
    if (ind==c1+c2+1)
    {
        if (Okay())
        ans++;

        return;
    }

    int i;

    for (i=0;i<=6;i++)
    {
        if (!used[i])
        {
            clock[ind]=i;
            used[i]=true;

            //cout<<"Add "<<i<<" to "<<ind<<endl;

            Batrak(ind+1);

            used[i]=false;
        }
    }

    return;
}

int main()
{
    Int v1=7,v2=7;
    scanf("%d %d",&n,&m);

    c1=1;
    c2=1;

    while(v1<n)
    {
        c1++;
        v1*=7LL;
    }

    while(v2<m)
    {
        c2++;
        v2*=7LL;
    }

    if (c1+c2>7)
    {
        printf("0\n");
        return 0;
    }

    Batrak(1);

    printf("%d\n",ans);

    return 0;
}