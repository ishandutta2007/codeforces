#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,k,p,t,x,y,m[1000],b[1001]={0},i,s=0,c=0;
    cin>>n>>k>>p>>x>>y;
    for(i=0;i<k;++i)
        {cin>>m[i];b[m[i]]++;if(m[i]<y) c++;s+=m[i];}
    if(c>n/2) {cout<<-1;exit(0);}
    if(s>x) {cout<<-1;exit(0);}
    t=min(n/2-c,n-k);
    for(i=0;i<t;++i)
        m[k++]=1;
    for(i=0;i<n-k;++i)
        m[k+i]=y;
    sort(m,m+n);
    s=0;
    for(i=0;i<n;++i)
    s+=m[i];
    if(s>x) {cout<<-1;exit(0);}
    for(i=0;i<n;++i)
        {   if(b[m[i]]>0) b[m[i]]--;
            else
            cout<<m[i]<<" ";
        }
    return 0;
}