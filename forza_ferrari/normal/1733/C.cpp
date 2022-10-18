#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<pair<int,int> > ans;
int t,n,a[100001];
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
        ans.clear();
        if(a[1]^a[n])
        {
            ans.emplace_back(1,n);
            if((a[1]+a[n])&1)
                a[n]=a[1];
            else
                a[1]=a[n];
        }
        for(int i=2;i<n;++i)
            if((a[1]+a[i])&1)
            {
                ans.emplace_back(1,i);
                a[i]=a[1];
            }
        for(int i=2;i<n;++i)
            if(a[n]^a[i])
                ans.emplace_back(i,n);
        cout<<ans.size()<<'\n';
        for(auto i:ans)
            cout<<i.first<<" "<<i.second<<'\n';
    }
    return 0;
}