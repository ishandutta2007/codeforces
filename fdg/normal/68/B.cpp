#include <iostream>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int a[10002]={0};

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    double l=0,r=1000;
    for(int t=0;t<300;t++)
    {
        double m=(l+r)/2,up=0,down=0;
        for(int i=0;i<n;i++)
        {
            if (a[i]>m-1e-9) up+=a[i]-m;
            else down+=m-a[i];
        }
        up*=1.0*(100-k); up/=100.0;
        if (up>down-1e-11) l=m;
        else r=m;
    }
    printf("%.7lf\n",(l+r)/2.0);
    return 0;
}