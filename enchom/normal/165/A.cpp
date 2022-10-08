#include <iostream>
using namespace std;
typedef long long Int;

struct point
{
    Int x,y;
};

point points[201];

int main()
{
    Int n;
    Int i,j;
    Int ctr=0;
    bool flag;
    
    cin>>n;
    
    for (i=1;i<=n;i++)
    {
        cin>>points[i].x;
        cin>>points[i].y;
    }
    for (i=1;i<=n;i++)
    {
        flag=false;
        for (j=1;j<=n;j++)
        {
            if (points[i].x>points[j].x && points[i].y==points[j].y)
            {
                flag=true;
                break;
            }
        }
        if (!flag)
        continue;
        
        flag=false;
        for (j=1;j<=n;j++)
        {
            if (points[i].x<points[j].x && points[i].y==points[j].y)
            {
                flag=true;
                break;
            }
        }
        if (!flag)
        continue;
        
        flag=false;
        for (j=1;j<=n;j++)
        {
            if (points[i].x==points[j].x && points[i].y>points[j].y)
            {
                flag=true;
                break;
            }
        }
        if (!flag)
        continue;
        
        flag=false;
        for (j=1;j<=n;j++)
        {
            if (points[i].x==points[j].x && points[i].y<points[j].y)
            {
                flag=true;
                break;
            }
        }
        if (!flag)
        continue;
        
        ctr++;
    }
    cout<<ctr<<endl;
    return 0;
}