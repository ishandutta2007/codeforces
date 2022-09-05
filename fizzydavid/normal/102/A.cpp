#include<iostream>
#include<cstdlib>
using namespace std;
int n,m,a[105];
bool b[105][105];
int main()
{
    int i,j,x,y,min=-100;
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=m;i++)cin>>x>>y,b[x][y]=true,b[y][x]=true;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)
    {
        if(b[i][j])
        {
            for(x=1;x<=n;x++)
            {
                if(b[x][j]&&b[i][x]&&x!=i)
                {
                    if(a[x]+a[j]+a[i]<min||min==-100){min=a[x]+a[j]+a[i];}
                    cout<<endl;
                }
            }
        }
    }
    if(min==-100)cout<<"-1";else cout<<min;
    return 0;
}