#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int n;
vector< pair<int,int> > cells;

int main()
{
    int i,j;

    scanf("%d", &n);

    for (i=1;i<=n;i++)
    {
        cells.push_back(make_pair(i, i));
        cells.push_back(make_pair(i+1, i));
        cells.push_back(make_pair(i, i+1));
    }

    ///Finish first
    cells.push_back(make_pair(0, 0));
    cells.push_back(make_pair(0, 1));
    cells.push_back(make_pair(1, 0));
    ///Finish last
    cells.push_back(make_pair(n+1, n+1));

    printf("%d\n", cells.size());

    for (i=0;i<cells.size();i++)
    {
        printf("%d %d\n", cells[i].first, cells[i].second);
    }
}