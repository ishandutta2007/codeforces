#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n,p,q;

char s[111];
int Choice[111];
bool F[111];

vector< pair<int,int> > ans;

int main()
{
    int i,j;
    int cur;

    scanf("%d %d %d",&n,&p,&q);

    scanf("%s",s+1);

    F[0]=true;

    for (i=1;i<=n;i++)
    {
        if (i>=p)
        {
            if (F[i-p])
            {
                Choice[i]=i-p;
                F[i]=true;
            }
        }

        if (i>=q)
        {
            if (F[i-q])
            {
                Choice[i]=i-q;
                F[i]=true;
            }
        }
    }

    if (!F[n])
    {
        printf("-1\n");
    }
    else
    {
        cur=n;

        while(cur!=0)
        {
            ans.push_back(make_pair( Choice[cur]+1,cur ));
            cur=Choice[cur];
        }

        printf("%d\n",(int)ans.size());
        for (i=(int)ans.size()-1;i>=0;i--)
        {
            for (j=ans[i].first;j<=ans[i].second;j++)
            {
                printf("%c",s[j]);
            }
            printf("\n");
        }
    }

    return 0;
}