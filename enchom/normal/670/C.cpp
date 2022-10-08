#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

map<int,int> mymap;
map<int,int>::iterator myit;
int n,m;

pair< pair<int,int>,int > movies[200111];

int main()
{
    int a;
    int i,j;
    int total=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a);

        myit=mymap.find(a);

        if (myit==mymap.end())
        {
            mymap.insert(make_pair(a,1));
        }
        else
        {
            (*myit).second=(*myit).second+1;
        }
    }

    scanf("%d",&m);

    for (i=1;i<=m;i++)
    {
        scanf("%d",&a);

        myit=mymap.find(a);

        if (myit==mymap.end())
        total=0;
        else
        total=(*myit).second;

        movies[i].first.first=total;

        movies[i].second=i;
    }

    for (i=1;i<=m;i++)
    {
        scanf("%d",&a);

        myit=mymap.find(a);

        if (myit==mymap.end())
        total=0;
        else
        total=(*myit).second;

        movies[i].first.second=total;
    }

    sort(movies+1,movies+1+m);

    printf("%d\n",movies[m].second);

    return 0;
}