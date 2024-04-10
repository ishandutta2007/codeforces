#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int t;
int n,k;
char str[2011];

vector< pair<int,int> > ans;

int v(char ch)
{
    if (ch == '(')
        return 1;
    else
        return -1;
}

void rev(int l,int r)
{
    int i;

    ans.push_back(make_pair(l, r));

    for (i=l; i <= r-(i-l); i++)
    {
        char swp = str[i];
        str[i] = str[r-(i-l)];
        str[r-(i-l)] = swp;
    }
}

void place(char ch, int ind)
{
    if (str[ind] == ch)
        return;

    int i;

    for (i=ind+1;i<=n;i++)
    {
        if (str[i] == ch)
        {
            rev(ind, i);
            return;
        }
    }
}

int main()
{
    int i,j;

    scanf("%d",&t);

    int test;

    for (test=1;test<=t;test++)
    {
        scanf("%d %d",&n,&k);

        scanf("%s",str+1);

        int pref = k-1;
        int sum = 0;

        ans.clear();

        int cur = 1;
        for (i=1;i<=pref;i++)
        {
            place('(', cur);
            place(')', cur+1);

            cur += 2;
        }

        int typeleft = n/2 - pref;

        for (i=1;i<=typeleft;i++)
        {
            place('(', cur);
            cur++;
        }

        for (i=1;i<=typeleft;i++)
        {
            place(')', cur);
            cur++;
        }

        printf("%d\n",(int)ans.size());

        for (i=0;i<ans.size();i++)
        {
            printf("%d %d\n",ans[i].first,ans[i].second);
        }
    }
}