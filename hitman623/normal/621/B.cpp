#include <iostream>

using namespace std;

int main()
{
    long n,x[200000],y[200000],i,s=0,b,c,j;
    cin>>n;
    for(i=0;i<n;++i)
        cin>>x[i]>>y[i];
    for(i=1000;i>=-1000;--i)
    {   b=0;c=0;
        for(j=0;j<n;++j)
        {
           if(y[j]-x[j]==i) b++;
           if(y[j]+x[j]==i+1000) c++;
        }
        if(b>1)
        s+=(b*(b-1))/2;
        if(c>1)
        s+=(c*(c-1))/2;
    }
    cout<<s;
    return 0;
}