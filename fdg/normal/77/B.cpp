#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        double a,b;
        cin >> a >> b;
        double ans=0;
        if (b==0) ans=1.0;
        else if (a==0) ans=0.5;
        else
        if (a<=4*b)
        {
            ans=2.0*(a*a/32.0+a*b/4.0)/a/b;
        }
        else
        {
            ans=((b*b/2.0+b*b)/b/2.0+a/4.0-b)/(a/4.0);
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}