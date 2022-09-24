#include<iostream>
using namespace std;
int x,y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>x>>y;
    if(x==1)
    {
        if(y==1)puts("=");
        else puts("<");
    }
    else if(y==1)puts(">");
    else
    {
        if(x==y)puts("=");
        else if(x==2)
        {
            if(y==3)puts("<");
            else if(y==4)puts("=");
            else puts(">");
        }
        else if(y==2)
        {
            if(x==3)puts(">");
            else if(x==4)puts("=");
            else puts("<");
        }
        else
        {
            if(x>y)puts("<");
            else puts(">");
        }
    }
    return 0;
}