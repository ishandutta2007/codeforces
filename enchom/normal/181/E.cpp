#include <iostream>
using namespace std;

int ABS(int a)
{
    if (a<0)
    return a*-1;
    else
    return a;
}

int main()
{
    int n,m,x1,y1,x2,y2;
    cin>>n>>m>>x1>>y1>>x2>>y2;
    
    if ( ABS(x1-x2)>4 || ABS(y1-y2)>4 || (ABS(y1-y2)==4 && ABS(x1-x2)==4) || ( ABS(y1-y2)==4 && ABS(x1-x2)==3 ) || ( ABS(y1-y2)==3 && ABS(x1-x2)==4 ) )
    cout<<"Second"<<endl;
    else
    cout<<"First"<<endl;
    
    return 0;
}