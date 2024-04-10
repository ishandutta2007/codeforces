#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define MAX 1000000

bool taken[1000001];
int n;
vector<int> ans;

int main()
{
    int k;
    int i;
    int doubles=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&k);

        taken[k]=true;
    }

    for (i=1;i<=500000;i++)
    {
        if (taken[i] && taken[MAX-i+1])
        {
            doubles++;
        }
    }

    for (i=1;i<=1000000;i++)
    {
        if (taken[i] && !taken[MAX-i+1])
        {
            ans.push_back(MAX-i+1);
        }
    }

    for (i=1;i<=500000;i++)
    {
        if (doubles==0)
        break;

        if (!taken[i] && !taken[MAX-i+1])
        {
            ans.push_back(i);
            ans.push_back(MAX-i+1);

            doubles--;
        }
    }

    printf("%d\n",(int)ans.size());

    for (i=0;i<(int)ans.size();i++)
    {
        printf("%d",ans[i]);

        if (i!=(int)ans.size()-1)
        {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}