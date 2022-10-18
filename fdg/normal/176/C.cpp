#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
//#include <omp.h>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,x1,y1,x2,y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    if (abs(x1-x2)<=4&&abs(y1-y2)<=2||abs(x1-x2)<=2&&abs(y1-y2)<=4||abs(x1-x2)<=3&&abs(y1-y2)<=3) puts("First");
    else puts("Second");
    return 0;
}