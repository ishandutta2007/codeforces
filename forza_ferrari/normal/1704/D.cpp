#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int t,n,m;
pair<int,int> a[100001];
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
signed main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        for(int i=1;i<=n;++i)
        {
            a[i].first=0;
            a[i].second=i;
            for(int j=1;j<=m;++j)
                a[i].first+=read()*j;
        }
        sort(a+1,a+n+1);
        cout<<a[n].second<<" "<<a[n].first-a[n-1].first<<'\n';
    }
    return 0;
}