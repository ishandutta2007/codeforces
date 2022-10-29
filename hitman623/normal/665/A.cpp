#include <iostream>

using namespace std;

int main()
{
    long a,ta,b,tb,m=0,c=0,i;char t[6];
    cin>>a>>ta>>b>>tb>>t;
    m=(((t[0]-'0')*10+t[1]-'0')-5)*60+(t[3]-'0')*10+t[4]-'0';
    for(i=0;i<=1140/b;++i)
    {
        if(b*i+tb>m && b*i<m+ta && b*i+tb!=m && b*i<1140)  {c++;}
    }
    cout<<c;
    return 0;
}