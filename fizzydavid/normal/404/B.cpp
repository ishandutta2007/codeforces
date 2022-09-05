#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std; 
double a,n,d;
int main()
{
    scanf("%lf %lf %lf",&a,&d,&n);
    double q=0.0;
    for(double i=1;i<=n;i++)
    {
        q+=d;
        q-=double(int(q/(4*a)))*4*a;
        if(q<a)
        {
            printf("%.8lf %.8lf\n",q,0.0);
        }
        else if(q>=a&&q<2*a)
        {
            printf("%.8lf %.8lf\n",a,q-a);
        }
        else if(q>=2*a&&q<3*a)printf("%.8f %.8f\n",a-(q-2*a),a);
        else printf("%.8lf %.8lf\n",0.0,a-(q-3*a));
    }
    return 0;
}