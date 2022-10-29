#include <bits/stdc++.h>
#define pb push_back

using namespace std;
long long cal ( long long a)
{
    long long s=0;
    while(a>0)
    {
        s+=a%10;
        a/=10;
    }
    return s;
}
int main()
{
    long long a,b,c,s,i,x;
    vector < long long > v;
    cin>>a>>b>>c;
    for(s=1;s<=81;++s)
    {
        x=b;
        for(i=0;i<a;++i)
        x*=s;
        x+=c;
        if(x>=1e9) break;
        if(cal(x)==s) v.pb(x);
    }
    cout<<v.size()<<endl;
    for(i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    return 0;
}