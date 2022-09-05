#include<iostream>
using namespace std;
#define abs(x) (x<0?-x:x)
int main()
{
    int a,b,c;cin>>a>>b>>c;a=abs(a);b=abs(b);
    if(c>=a+b&&!((c-a-b)&1))cout<<"Yes";else cout<<"No";
}