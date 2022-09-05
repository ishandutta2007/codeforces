#include<iostream>
#include<cstdlib>
using namespace std;
#define end return 0
bool lin[105][105],isil[105];
int n,m;
int link(int x1,int x2)
{
    isil[x2]=1;
    for(int i=1;i<=n;i++)if(lin[i][x2]&&!isil[i])link(x2,i);
}
int main()
{
    int a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>a>>b,lin[a][b]=lin[b][a]=1;
    if(n==m)
    {   link(1,2);
        for(int i=1;i<=n;i++)if(!isil[i]){cout<<"NO";end;};
        cout<<"FHTAGN!";end;
    }
    cout<<"NO";end;
}