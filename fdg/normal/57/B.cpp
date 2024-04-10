#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <memory.h>
#include <ctime>
#include <set>
#include <cmath>

#define ll long long

using namespace std;

ll a[100003]={0},b[100003]={0},c[100003]={0},ans=0;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k,d;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
        scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]);
    for(int t=0;t<k;t++)
    {
        scanf("%d",&d);
        for(int i=0;i<m;i++)
        {
            if (a[i]<=d&&d<=b[i]) ans+=c[i]-a[i]+d;
        }
    }
    cout << ans << endl;
    return 0;
}