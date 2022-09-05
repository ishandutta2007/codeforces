#include<iostream>
#include<cstdlib>
using namespace std;
int consert(int x,int y)
{
    return (x>=y)?consert(x%y,y)+x/y*10:x;
}
int main()
{
    int a;
    cin>>a;
    for(int i=1;i<a;i++)
    {
    for(int j=1;j<a;j++)
    {
        int d=i*j;
        cout<<consert(d,a)<<" ";
    }
    cout<<endl;
    }
    return 0;
}