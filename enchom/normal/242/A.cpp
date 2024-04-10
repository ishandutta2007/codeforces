#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;

struct outcome
{
    Int vasya,petya;
};

vector<outcome> outcomes;

int main()
{
    Int x,y,a,b;
    Int i,j;
    outcome h;
    
    scanf("%I64d %I64d %I64d %I64d",&x,&y,&a,&b);
    
    for (i=a;i<=x;i++)
    {
        for (j=b;j<i && j<=y;j++)
        {
            h.vasya=i;
            h.petya=j;
            outcomes.push_back(h);
        }
    }
    cout<<outcomes.size()<<endl;
    for (i=0;i<outcomes.size();i++)
    {
        printf("%I64d %I64d\n",outcomes[i].vasya,outcomes[i].petya);
    }
    return 0;
}