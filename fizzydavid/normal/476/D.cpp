#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int x,y;cin>>x>>y;
    cout<<(x*6-1)*y<<endl;
    for(int i=0;i<x;i++)cout<<(i*6+1)*y<<" "<<(i*6+2)*y<<" "<<(i*6+3)*y<<" "<<(i*6+5)*y<<endl;
    return 0;
}