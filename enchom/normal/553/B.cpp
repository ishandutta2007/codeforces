#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;

Int n,k;

vector<int> P;

Int Answer[51];

int main()
{
    int i;
    int uk;

    cin>>n>>k;

    Answer[0]=1;
    Answer[1]=1;

    for (i=2;i<=n;i++)
    {
        Answer[i]=Answer[i-1]+Answer[i-2];
    }

    uk=1;
    while(k>0 && uk<=n)
    {
        if (k<=Answer[n-uk])
        {
            P.push_back(uk);
            uk++;
        }
        else
        {
            k-=Answer[n-uk];
            P.push_back(uk+1);
            P.push_back(uk);
            uk+=2;
        }
    }

    for (i=0;i<P.size();i++)
    {
        if (i!=0)
        cout<<" ";

        cout<<P[i];
    }
    cout<<endl;

    return 0;
}