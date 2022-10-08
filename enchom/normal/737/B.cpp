#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n,a,b,k;
char grid[200111];

vector<int> kills;
vector<int> ans;

void Solve(int L,int R)
{
    int cur=L+b-1;

    while(cur<=R)
    {
        kills.push_back(cur);
        cur+=b;
    }

    return;
}

int main()
{
    int i;
    int last1=0;

    scanf("%d %d %d %d",&n,&a,&b,&k);

    scanf("%s",grid+1);

    for (i=1;i<=n;i++)
    {
        if (grid[i]=='1')
        {
            Solve(last1+1,i-1);
            last1=i;
        }
    }

    if (grid[n]!='1')
    {
        Solve(last1+1,n);
    }

    while(kills.size()>=a)
    {
        ans.push_back(kills.back());
        kills.pop_back();
    }

    printf("%d\n",(int)ans.size());

    for (i=0;i<ans.size();i++)
    {
        if (i!=0)
        printf(" ");

        printf("%d",ans[i]);
    }
    printf("\n");

    return 0;
}