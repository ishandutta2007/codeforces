#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int kol[100003]={0};
vector < pair <int,int> > v;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        kol[a]++;
        v.push_back(make_pair(a,i));
    }
    sort(v.begin(),v.end());
    bool norm=true;
    for(int i=2;i<=100000;i++)
    {
        if (kol[i-1]<kol[i])
        {
            norm=false;
            break;
        }
    }
    if (!norm)
    {
        printf("-1\n");
        return 0;
    }
    int k=0,num=kol[1];
    for(int i=0;i<v.size();i++)
    {
        if (i>0&&v[i-1].first!=v[i].first) k=0;
        kol[v[i].second]=++k;
    }
    printf("%d\n",num);
    for(int i=0;i<n;i++)
    {
        if (i==0) printf("%d",kol[i]);
        else printf(" %d",kol[i]);
    }
    printf("\n");
    return 0;
}