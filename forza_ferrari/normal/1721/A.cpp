#include<iostream>
#include<cstdio>
using namespace std;
int t;
char a,b,c,d;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        if(a==b&&a==c&&a==d)
        {
            cout<<"0\n";
            continue;
        }
        if((a==b&&c==d)||(a==c&&b==d)||(a==d&&b==c))
        {
            cout<<"1\n";
            continue;
        }
        if((a==b&&a==c)||(a==b&&a==d)||(a==c&&a==d)||(b==c&&b==d))
        {
            cout<<"1\n";
            continue;
        }
        if(a==b||a==c||a==d||b==c||b==d||c==d)
        {
            cout<<"2\n";
            continue;
        }
        cout<<"3\n";
    }
    return 0;
}