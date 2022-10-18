#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int t,n,a[200001],b[200001],ans[200001];
multiset<int> s;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
int main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;++i)
            a[i]=read();
        for(int i=1;i<=n;++i)
            b[i]=read();
        for(int i=1;i<=n;++i)
            cout<<*lower_bound(b+1,b+n+1,a[i])-a[i]<<" ";
        cout<<'\n';
        s.clear();
        int pos=n;
        for(int i=n;i>=1;--i)
        {
            while(pos>=1&&b[pos]>=a[i])
                s.emplace(b[pos--]);
            ans[i]=*--s.end()-a[i];
            s.erase(s.begin());
        }
        for(int i=1;i<=n;++i)
            cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
}