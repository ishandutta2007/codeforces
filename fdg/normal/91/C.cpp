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

int color[100005]={0};

int repr(int x)
{
    if (color[x]==x) return x;
    return color[x]=repr(color[x]);
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b,res=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i) color[i]=i;
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&a,&b);
        a=repr(a-1); b=repr(b-1);
        if (a==b) res=(res+res+1)%1000000009;
        else color[a]=b;
        printf("%d\n",res);
    }
    return 0;
}