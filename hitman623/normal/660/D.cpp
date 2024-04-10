#include <bits/stdc++.h>

using namespace std;

int main()
{
    map < pair <long,long> , long > a;
    long n,x[2002],y[2002],s=0,m;
    long i,j;
    cin>>n;
    for(i=0;i<n;++i)
        cin>>x[i]>>y[i];
       // memset(a,0,sizeof(a));
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;++j)
        {
            a[make_pair(x[i]+x[j],y[i]+y[j])]++;
        }
    }
    map < pair <long,long> , long > ::iterator it;
    for(it=a.begin();it!=a.end();++it)
    {
        //cout<<(it->first.first)<<"  "<<(it->first.second)<<"  "<<(it->second)<<endl;
        m=long(it->second);
		s+=(m*(m-1))/2;
        //cout<<s<<endl;
    }
    cout<<s;
    return 0;
}