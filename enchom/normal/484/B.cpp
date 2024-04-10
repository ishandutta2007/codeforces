#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include <time.h>
using namespace std;

int curans;
int ans[2000001];

bool Exists[1000001];

vector<int> mvs[2000001];

int n;
int a[400001];
int curnum;
int maxans=0;

void UpdateAnswer()
{
    while(ans[curans]==0)
    {
        curans++;
    }

    return;
}

int main()
{
    //freopen("t.txt","r",stdin);
    //freopen("sample.txt","r",stdin);

    int i,j;
    int lst;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);

        Exists[ a[i] ]=true;
    }

    sort(a+1,a+1+n);

    ans[ a[1] ]=1;

    mvs[ 2*a[1] ].push_back(a[1]);

    curans=a[1];

    for (i=1;i<=1000000;i++)
    {
        lst=mvs[i].size();
        lst--;

        while(!mvs[i].empty())
        {
            ans[ i-mvs[i][lst] ]--;
            ans[i]++;
            mvs[ i+mvs[i][lst] ].push_back(mvs[i][lst]);

            mvs[i].pop_back();

            lst--;
        }

        if (Exists[i])
        {
            UpdateAnswer();

            if (i-curans>maxans)
            maxans=i-curans;

            ans[i]++;
            mvs[2*i].push_back(i);
        }
    }

    printf("%d\n",maxans);

    return 0;
}