#include <iostream>
#include <algorithm>
using namespace std;

struct point
{
    int x,y;
};

point rob[4];
int rL=0;

int main()
{
    int n,m;
    char input;
    int i,j;
    
    cin>>n>>m;
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            cin>>input;
            if (input=='*')
            {
                rL++;
                rob[rL].x=i;
                rob[rL].y=j;
            }
        }
    }
    
    if (rob[1].x==rob[2].x)
    {
        if (rob[3].y==rob[1].y)
        {
            cout<<rob[3].x<<" "<<rob[2].y<<endl;
            return 0;
        }
        else if (rob[3].y==rob[2].y)
        {
            cout<<rob[3].x<<" "<<rob[1].y<<endl;
            return 0;
        }
    }
    else if (rob[1].y==rob[2].y)
    {
        cout<<rob[1].x<<" "<<rob[3].y<<endl;
        return 0;
    }
    else
    {
        cout<<rob[1].x<<" "<<rob[2].y<<endl;
    }
    return 0;
}