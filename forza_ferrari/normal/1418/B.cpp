#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int t,n,a[101],b[101],c[101];
multiset<int> s;
int main()
{
    cin>>t;
    while(t--)
    {
        s.clear();
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=1;i<=n;++i)
        {
            cin>>b[i];
            if(b[i])
                c[i]=a[i];
            else
                s.emplace(a[i]);
        }
        for(int i=1;i<=n;++i)
            if(!b[i])
            {
                c[i]=*--s.end();
                s.erase(--s.end());
            }
        for(int i=1;i<=n;++i)
            cout<<c[i]<<" ";
        cout<<'\n';
    }
    return 0;
}