#include<iostream>
#include<cstdio>
using namespace std;
double k,d,t,qwq,ans;
int main()
{
    cin>>k>>d>>t;
    double r=((long long)((k-1)/d)+1)*d,val=(long long)(2*t/(r+k));
    qwq=2*t-(r+k)*val;
    ans+=val*r;
    if(qwq<2*k)
        ans+=qwq/2;
    else
        ans+=k+qwq-2*k;
    printf("%.1lf\n",ans);
    return 0;
}