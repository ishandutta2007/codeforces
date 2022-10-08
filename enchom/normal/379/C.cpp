#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;

struct person
{
    int id;
    int a;
};

person people[300001];
int n;
int NewRating[300001];

bool SortF(person a,person b)
{
    return a.a<b.a;
}

int main()
{
    int i;
    int Rating=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&people[i].a);
        people[i].id=i;
    }

    sort(people+1,people+1+n,SortF);

    for (i=1;i<=n;i++)
    {
        if (people[i].a>Rating)
        {
            Rating=people[i].a;
        }

        NewRating[ people[i].id ]=Rating;

        Rating++;
    }

    for (i=1;i<=n;i++)
    {
        printf("%d",NewRating[i]);

        if (i!=n)
        {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}