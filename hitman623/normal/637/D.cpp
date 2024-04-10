#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,s,d,aa[200005],cur=0,i,f=1,t;
    vector < long long > a;
    cin>>n>>m>>s>>d;
    for(i=0;i<n;++i)
    cin>>aa[i];
    sort(aa,aa+n);
    t=aa[0];
    if(t<=s) {cout<<"IMPOSSIBLE";exit(0);}
    aa[n]=100000000009;
    for(i=1;i<=n;++i)
    {
        if(aa[i]-aa[i-1]-1>s)
            {
                if(aa[i-1]-t+1>=d)
                {cout<<"IMPOSSIBLE";exit(0);}
                a.push_back(aa[i-1]);
                t=aa[i];
                f=0;
            }
        else if(f==0)
        { t=aa[i-1];f=1; }
    }
    for(i=0;i<a.size();++i)
    {
        if(a[i]+1-d>cur+s)
            {
             cout<<"RUN "<<a[i]+1-d-cur<<endl;
             cout<<"JUMP "<<d<<endl;
            }
        else
            {
             cout<<"RUN "<<s<<endl;
             cout<<"JUMP "<<a[i]+1-s-cur<<endl;
            }
        cur=a[i]+1;
    }
    if(m-cur>0) cout<<"RUN "<<m-cur;
    return 0;
}