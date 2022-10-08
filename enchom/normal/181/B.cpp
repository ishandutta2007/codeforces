#include <iostream>
using namespace std;

struct point
{
    int x,y;
};

point pts[3001];
bool place[2001][2001];
int newx,newy;

int main()
{
    int n;
    int i,j;
    int xi,yi;
    int ctr=0;
    
    
    cin>>n;
    
    for (i=0;i<=2000;i++)
    {
        for (j=0;j<=2000;j++)
        {
            place[i][j]=false;
        }
    }
    for (i=1;i<=n;i++)
    {
        cin>>xi>>yi;
        xi+=1000;
        yi+=1000;
        pts[i].x=xi;
        pts[i].y=yi;
        place[xi][yi]=true;
    }
    for (i=1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            if ( (pts[i].x+pts[j].x)%2==0 )
            {
                newx=(pts[i].x+pts[j].x)/2;
            }
            else
            continue;
            
            if ( (pts[i].y+pts[j].y)%2==0 )
            {
                newy=(pts[i].y+pts[j].y)/2;
            }
            else
            continue;
            
            if (place[newx][newy])
            ctr++;
        }
    }
    cout<<ctr<<endl;
    return 0;
}