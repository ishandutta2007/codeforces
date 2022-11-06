#include<bits/stdc++.h>
using namespace std;
int n,i,t,x,a,b,c,d;
int main()
{
    cin>>a>>b>>c>>d;
    t=min(a,min(c,d));
    a=a-t;
    x=min(a,b);
    cout<<t*256+x*32<<endl;
}