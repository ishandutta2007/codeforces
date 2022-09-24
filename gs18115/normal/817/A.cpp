#include<iostream>
#include<cmath>
using namespace std;
int a,b,c,d,e,f;
int main()
{
    cin>>a>>b>>c>>d>>e>>f;
    int x=abs(c-a);
    int y=abs(d-b);
    e=abs(e);
    f=abs(f);
    if(x%e!=0||y%f!=0)
        cout<<"NO";
    else if(x/e+y/f&1)
        cout<<"NO";
    else
        cout<<"YES";
    cout<<endl;
    return 0;
}