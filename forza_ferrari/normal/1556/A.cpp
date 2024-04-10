#include<iostream>
#include<cstdio>
using namespace std;
int t,a,b;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        puts(a==b? a? "1":"0":(a-b)&1? "-1":"2");
    }
    return 0;
}