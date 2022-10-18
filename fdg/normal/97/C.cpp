#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    double p[103],res=0;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        scanf("%lf",&p[i]);
//    if (n%2==0) res=p[n/2];
    for(int i=0;2*i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            double y=(n/2.0-i)/(j-i),x=1-y;
            if (y<=1&&x*p[i]+y*p[j]>res) res=x*p[i]+y*p[j];
        }
    }
    printf("%.10lf\n",res);
    return 0;
}