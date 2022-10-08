#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n,m;
vector<int> ans;

int main()
{
    int i;

    scanf("%d %d",&n,&m);

    int num = 1;
    while(num <= n)
    {
        if (m >= (num-1) / 2)
            m -= (num-1) / 2;
        else
            break;

        ans.push_back(num);
        num++;
    }

    if (num > n && m > 0)
    {
        printf("-1\n");
        return 0;
    }

    if (m > 0)
    {
        ans.push_back(num + (num - 1 - 2*m));
    }

    if (ans.size() < n)
        ans.push_back(100000000);
    while(ans.size() < n)
        ans.push_back(ans.back() + 19999);

    for (i=0;i<ans.size();i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");

    return 0;
}