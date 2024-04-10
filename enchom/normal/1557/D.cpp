#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct event
{
    int pos;
    int row;
    int change;
};

int n, m;
vector<event> events;

bool SE(event A, event B)
{
    if (A.pos != B.pos)
        return A.pos < B.pos;
    else
        return A.change < B.change;
}

int tally[300111];

set<int> activeRows;

vector<int> lookups[300111];

void addLookup(int A, int B)
{
    if (A > B)
        swap(A, B);

    lookups[B].push_back(A);
}

int F[300111];
int best[300111];

set<int> kept;

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);

    for (i=1;i<=m;i++)
    {
        int row, l, r;

        scanf("%d %d %d", &row, &l, &r);

        event e;
        e.pos = l;
        e.row = row;
        e.change = 1;
        events.push_back(e);

        e.pos = r + 1;
        e.row = row;
        e.change = -1;
        events.push_back(e);
    }

    sort(events.begin(), events.end(), SE);

    for (i=0;i<events.size();i++)
    {
        event e = events[i];

        tally[e.row] += e.change;

        if (tally[e.row] == 0) /// Removing
        {
            activeRows.erase(e.row);
        }
        else if (tally[e.row] == 1 && e.change == 1) /// Adding
        {
            auto myit = activeRows.insert(e.row).first;

            if (myit != activeRows.begin())
            {
                auto prev = myit;
                prev--;

                addLookup((*prev), (*myit));
            }

            auto nxt = myit;
            nxt++;

            if (nxt != activeRows.end())
            {
                addLookup((*myit), (*nxt));
            }
        }
    }

    int maxans = 0;
    int bestans = 0;
    F[0] = 0;

    for (i=1;i<=n;i++)
    {
        F[i] = 1;
        best[i] = 0;
        for (j=0;j<lookups[i].size();j++)
        {
            int prev = lookups[i][j];

            if (F[prev] + 1 > F[i])
            {
                F[i] = F[prev] + 1;
                best[i] = prev;
            }
        }

        if (F[i] > maxans)
        {
            maxans = F[i];
            bestans = i;
        }
    }

    while(bestans != 0)
    {
        kept.insert(bestans);
        bestans = best[bestans];
    }

    printf("%d\n", n - maxans);

    bool first = true;
    for (i=1;i<=n;i++)
    {
        if (kept.find(i) != kept.end())
            continue;

        if (!first)
            printf(" ");
        first = false;

        printf("%d", i);
    }
    printf("\n");

    return 0;
}