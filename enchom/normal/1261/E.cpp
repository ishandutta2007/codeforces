#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int a[1011];
pair<int,int> sorted[1011];

int ans[1011][1011];

int main()
{
    int i,j;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);

        sorted[i] = make_pair(a[i], i);
    }

    sort(sorted+1,sorted+1+n);
    reverse(sorted+1,sorted+1+n);

    int inflated = 0;
    if (sorted[1].first < n)
    {
        inflated = n - sorted[1].first;
        sorted[1].first = n;
    }

    int rows = n;
    int pre = 1;
    int dump = n+1;
    while(pre <= n && rows > 0)
    {
        int mv = 0;
        int mind = 0;
        //cout<<rows<<" rows with dump "<<dump<<endl;
        //cout<<"pre="<<pre<<endl;

        if (sorted[pre].first == 0)
            break;

        for (i=1;i<=sorted[pre].first;i++)
        {
            ans[i][ sorted[pre].second ] = 1;
        }

        /*cout<<"Unloading "<<sorted[pre].first<<endl;
        for (i=pre;i<=n;i++)
        {
            cout<<sorted[i].first<<" ";
        }
        cout<<endl;*/

        for (i=pre+1;i<=n;i++)
        {
            if (sorted[i].first == sorted[pre].first)
            {
                //cout<<"IS!"<<endl;
                ans[dump][ sorted[i].second ] = 1;
                sorted[i].first--;
            }
        }

        dump = rows;
        rows--;

        for (i=n;i>pre;i--)
        {
            if (sorted[i].first > 0 && rows > sorted[pre+1].first)
            {
                ans[rows][ sorted[i].second ] = 1;
                sorted[i].first--;
                rows--;
            }
        }

        pre++;
    }

    if (inflated > 0)
    {
        for (i=1;i<=n;i++)
        {
            if (inflated == 0)
                break;

            ans[i][ sorted[1].second ] = 0;

            inflated--;
        }
    }

    printf("%d\n",n+1);
    for (i=1;i<=n+1;i++)
    {
        for (j=1;j<=n;j++)
        {
            printf("%d",ans[i][j]);
        }
        printf("\n");
    }
}