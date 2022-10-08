#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;

vector<Int> places[100001];
Int n;
vector< pair<Int,Int> > ans;

int main()
{
    Int i,j;
    Int x;
    bool progression;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&x);

        places[x].push_back(i);
    }

    for (i=1;i<=100000;i++)
    {
        progression=true;

        if (places[i].size()==0)
        continue;

        for (j=2;j<places[i].size();j++)
        {
            if (places[i][j]-places[i][j-1]!=places[i][1]-places[i][0])
            {
                progression=false;
                break;
            }
        }

        if (!progression)
        continue;

        if (places[i].size()==1)
        {
            ans.push_back( make_pair(i,0) );
        }
        else
        {
            ans.push_back( make_pair(i,places[i][1]-places[i][0]) );
        }
    }

    printf("%I64d\n",(Int)ans.size());

    for (i=0;i<(Int)ans.size();i++)
    {
        printf("%I64d %I64d\n",ans[i].first,ans[i].second);
    }

    return 0;
}