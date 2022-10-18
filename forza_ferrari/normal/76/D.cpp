#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long a,b;
int main()
{
    cin>>a>>b;
    if(a<b||((a-b)&1))
    {
        puts("-1");
        return 0;
    }
    unsigned long long x=(a-b)>>1,y=a-x;
    if(x^y^b)
        puts("-1");
    else
        cout<<x<<" "<<y<<'\n';
    return 0;
}