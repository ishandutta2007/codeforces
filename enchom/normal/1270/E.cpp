#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n;
pair<int,int> pts[1111];

vector<int> A;

bool split()
{
    int i;

    A.clear();

    for (i=1;i<=n;i++)
    {
        if ( (pts[i].first + pts[i].second) % 2 == 0 )
            A.push_back(i);
    }

    return A.size() != 0 && A.size() != n;
}

void trans()
{
    int i;

    if (A.size() == 0)
    {
        for (i=1;i<=n;i++)
        {
            pts[i].first++;
        }
    }

    for (i=1;i<=n;i++)
    {
        int nx = (pts[i].first - pts[i].second) / 2;
        int ny = (pts[i].first + pts[i].second) / 2;

        pts[i] = make_pair(nx, ny);
    }

    return;
}

int main()
{
    int i;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&pts[i].first,&pts[i].second);
    }

    while(!split())
    {
        trans();
    }

    printf("%d\n",A.size());

    for (i=0;i<A.size();i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");

    return 0;
}