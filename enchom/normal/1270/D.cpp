#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n,k;

string numtostr(int num)
{
    string s;

    if (num == 0)
        return "0";

    while(num > 0)
    {
        s.push_back(num%10 + '0');
        num /= 10;
    }

    reverse(s.begin(), s.end());

    return s;
}

char buf[1000111];
int bL = 0;

void add(int num)
{
    string s = numtostr(num);
    int i;

    buf[bL] = ' ';
    bL++;

    for (i=0;i<s.length();i++)
    {
        buf[bL] = s[i];
        bL++;
    }

    buf[bL] = 0;

    return;
}

pair<int,int> ask()
{
    printf("%s\n",buf);
    fflush(stdout);

    int a,b;

    scanf("%d %d",&a,&b);

    bL = 1;
    buf[0] = '?';

    return make_pair(a,b);
}

int main()
{
    int i,j;

    bL = 1;
    buf[0] = '?';

    scanf("%d %d",&n,&k);

    for (i=1;i<=k;i++)
    {
        add(i);
    }

    pair<int,int> base = ask();

    for (i=1;i<=k+1;i++)
    {
        if (i == base.first)
            continue;

        add(i);
    }

    pair<int,int> comp = ask();
    bool smaller = true;

    if (comp.second > base.second)
        smaller = false;

    int sameside = 0;

    for (i=1;i<=k;i++)
    {
        if (i == base.first)
            continue;

        for (j=1;j<=k+1;j++)
        {
            if (j == i)
                continue;

            add(j);
        }

        pair<int,int> res = ask();

        if (res.second == base.second)
            sameside++;
    }

    int m;

    if (smaller)
        m = sameside + 1;
    else
        m = k - sameside;

    printf("! %d\n",m);
    fflush(stdout);

    return 0;
}