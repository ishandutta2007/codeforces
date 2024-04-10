#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a,cur=1;
    vector <int> ans;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        if (a==cur)
        {
            ans.push_back(2001+i);
            cur++;
        }
    }
    printf("%d\n",ans.size());
    if (ans.size()>0)
    {
        printf("%d",ans[0]);
        for(int i=1;i<ans.size();i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}