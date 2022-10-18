#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stack>

#define ll long long
#define INF 10000000

using namespace std;

vector <int> v1,v2,d,a;
int what[1000002]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    v1.resize(n); v2.resize(n);
    for(int i=0;i<n;i++)
        scanf("%d",&v1[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&v2[i]);
    reverse(v2.begin(),v2.end());
    a.resize(n);
    for(int i=1;i<=n;i++)
        what[v1[i-1]]=i;
    for(int i=0;i<n;i++)
        a[i]=what[v2[i]];
    d.resize(n+1, INF);
    d[0] = -INF;
    for (int i=0; i<n; i++)
    {
        unsigned j = upper_bound (d.begin(), d.end(), a[i]) - d.begin() - 1;
        if (d[j] < a[i] && a[i] < d[j+1])
            d[j+1] = a[i];
    }
    int res=0;
    for(int i=0;i<=n;i++)
        if (d[i]!=INF) res=i;
    cout << res << endl;
    return 0;
}