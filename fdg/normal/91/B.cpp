#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <set>
#pragma comment(linker, "/STACK:65777216")

#define ll long long

using namespace std;

vector < pair <int,int> > v;
int res[100005]={0};
vector <int> vv;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a;
    scanf("%d",&n);
    v.clear();
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        v.push_back(make_pair(a,n-i-1));
    }
    sort(v.begin(),v.end());
    int mi=1000000;
    for(int i=0;i<v.size();i++)
    {
        vv.clear();
        int f=i;
        for(;i<v.size();i++)
            if (v[i].first==v[f].first)
            {
                if (v[i].second>mi)
                {
                    res[n-v[i].second-1]=v[i].second-mi-1;
                } else res[n-v[i].second-1]=-1;
                vv.push_back(v[i].second);
            } else break;
        i--;
        for(int j=0;j<vv.size();j++)
            mi=min(mi,vv[j]);
    }
    printf("%d",res[0]);
    for(int i=1;i<n;i++)
        printf(" %d",res[i]);
    printf("\n");
    return 0;
}