#include<iostream>
#include<cstdio>
using namespace std;
int t,x,y,ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        if(x>=2&&x<=3&&y>=2&&y<=3)
            cout<<"2 2\n";
        else
            cout<<"1 1\n";
    }
    return 0;
}