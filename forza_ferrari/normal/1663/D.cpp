#include<iostream>
using namespace std;
int main()
{
    string s;
    int x;
    cin>>s>>x;
    if(s=="ABC")
    {
        cout<<(x<=1999? "YES":"NO")<<'\n';
        return 0;
    }
    if(s=="ARC")
    {
        cout<<(x<=2799? "YES":"NO")<<'\n';
        return 0;
    }
    cout<<(x>=1200? "YES":"NO")<<'\n';
    return 0;
}