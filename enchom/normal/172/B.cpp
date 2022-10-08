#include <iostream>
using namespace std;

typedef long long Int;

Int a,b,r,m;
Int used[100001];

int main()
{
    Int i,step;
    
    cin>>a>>b>>m>>r;
    
    for (i=0;i<=100000;i++)
    used[i]=0;
    
    step=1;
    used[r]=step;
    
    while(1)
    {
        step++;
        r=(a*r+b)%m;
        if (used[r]!=0)
        {
            cout<<step-used[r]<<endl;
            return 0;
        }
        used[r]=step;
    }
    return 0;
}