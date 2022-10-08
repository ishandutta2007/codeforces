#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,int> h[2001];
int n;
int tasks[2001];
vector<int> doubles;
vector<int> many;

int main()
{
    int i;
    bool done;
    bool done2;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&h[i].first);
        tasks[ h[i].first ]++;
        h[i].second=i;
    }

    for (i=1;i<=2000;i++)
    {
        if (tasks[i]==2)
        doubles.push_back(i);
        else if (tasks[i]>2)
        many.push_back(i);
    }

    if (many.empty() && doubles.size()<2)
    {
        printf("NO\n");
        return 0;
    }

    sort(h+1,h+1+n);

    printf("YES\n");

    if (!many.empty())
    {
        for (i=1;i<=n;i++)
        {
            printf("%d",h[i].second);
            if (i!=n)
            printf(" ");
        }
        printf("\n");

        ///

        done=false;
        for (i=1;i<=n;i++)
        {
            if (!done)
            {
                if (h[i].first==h[i+1].first && h[i+1].first==h[i+2].first)
                {
                    done=true;
                    printf("%d %d %d",h[i+2].second,h[i+1].second,h[i].second);
                    if (i+2!=n)
                    printf(" ");
                    i+=2;
                    continue;
                }
            }

            printf("%d",h[i].second);
            if (i!=n)
            printf(" ");
        }
        printf("\n");

        ///

        done=false;
        for (i=1;i<=n;i++)
        {
            if (!done)
            {
                if (h[i].first==h[i+1].first && h[i+1].first==h[i+2].first)
                {
                    done=true;
                    printf("%d %d %d",h[i+1].second,h[i+2].second,h[i].second);
                    if (i+2!=n)
                    printf(" ");
                    i+=2;
                    continue;
                }
            }

            printf("%d",h[i].second);
            if (i!=n)
            printf(" ");
        }
        printf("\n");
    }
    else
    {
        for (i=1;i<=n;i++)
        {
            printf("%d",h[i].second);
            if (i!=n)
            printf(" ");
        }
        printf("\n");

        ///

        done=false;
        for (i=1;i<=n;i++)
        {
            if (!done)
            {
                if (h[i].first==h[i+1].first)
                {
                    done=true;
                    printf("%d %d",h[i+1].second,h[i].second);
                    if (i+1!=n)
                    printf(" ");

                    i++;
                    continue;
                }
            }

            printf("%d",h[i].second);
            if (i!=n)
            printf(" ");
        }
        printf("\n");

        ///

        done=false;
        done2=false;
        for (i=1;i<=n;i++)
        {
            if (!done)
            {
                if (h[i].first==h[i+1].first)
                {
                    done=true;
                }
            }
            else if (!done2)
            {
                if (h[i].first==h[i+1].first)
                {
                    done2=true;
                    printf("%d %d",h[i+1].second,h[i].second);
                    if (i+1!=n)
                    printf(" ");

                    i++;
                    continue;
                }
            }

            printf("%d",h[i].second);
            if (i!=n)
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}