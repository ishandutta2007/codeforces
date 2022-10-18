#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <memory.h>
//#pragma comment(linker, "/STACK:60777216")

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    double x,y;
    cin >> x >> y;
    double dist=sqrt(x*x+y*y);
    int d=dist;
    if (x==0||y==0||fabs(dist-d)<1e-8) printf("black\n");
    else
        if (x>=0&&y>=0||x<=0&&y<=0)
        {
            if (d%2==0) printf("black\n");
            else printf("white\n");
        }
        else
        {
            if (d%2==1) printf("black\n");
            else printf("white\n");
        }
    return 0;
}