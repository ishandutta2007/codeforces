#include <stdio.h>
#include <complex>
#include <math.h>
#include <algorithm>

using namespace std;

complex<int> O[2];
int r[2];

int main()
{
    for(int i=0; i < 2; ++i){
        int x, y;
        scanf("%d%d%d", &x, &y, r+i);
        O[i]=complex<int>(x, y);
    }
    //double ans=max(0.0, sqrt(double(norm(O[0]-O[1])))-r[0]-r[1]);
    double ans, dis;
    dis=sqrt(double(norm(O[0]-O[1])));
    if(dis > r[0]+r[1])
        ans=dis-r[0]-r[1];
    else if(dis+r[0] < r[1])
        ans=r[1]-dis-r[0];
    else if(dis+r[1] < r[0])
        ans=r[0]-dis-r[1];
    else
        ans=0;
    printf("%.6lf", ans/2.0);
    return 0;
}