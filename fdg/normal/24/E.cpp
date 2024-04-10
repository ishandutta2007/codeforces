#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
/*
#ifndef ONLINE_JUDGE
int AA=(int)freopen("input.txt","r",stdin);
int BB=(int)freopen("output.txt","w",stdout);
#endif
*/
#define ll long long

using namespace std;

int p[500003]={0},v[500003]={0},n;

bool check(double time)
{
    double maxpos=0;
    for(int i=0;i<n;i++)
        if (v[i]>0)
        {
            maxpos=time*v[i]+p[i];
            for(int j=i+1;j<n;j++)
            {
                if (v[j]>0)
                {
                    if (maxpos<time*v[j]+p[j]) maxpos=time*v[j]+p[j];
                }
                else if (maxpos>=time*v[j]+p[j]) return true;
            }
            break;
        }
    return false;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        scanf("%d%d",&p[i],&v[i]);
    double l=0,r=1000000002;
//  while(r-l>=1e-9)
    for(int t=0;t<=70;t++)
    {
        double m=(l+r)/2;
        if (check(m)) r=m;
        else l=m;
    }
    if (fabs(r-1000000002)<1e-9) printf("-1\n");
    else printf("%.15f\n",(l+r)/2);
    return 0;
}