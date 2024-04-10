#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[100001],p[100001];
inline bool cmp(int x,int y)
{
    return a[x]<a[y];
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            p[i]=i;
        }
        sort(p+1,p+n+1,cmp);
        cout<<p[1]<<" "<<p[n]<<'\n';
    }
    return 0;
}