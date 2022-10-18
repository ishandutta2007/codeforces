#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,x,y,d;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x>>y>>d;
        if((x-d<=1&&x+d>=n)||(y-d<=1&&y+d>=m)||(x-d<=1&&y-d<=1)||(x+d>=n&&y+d>=m))
        {
            cout<<"-1\n";
            continue;
        }
        cout<<n+m-2<<'\n';
    }
    return 0;
}