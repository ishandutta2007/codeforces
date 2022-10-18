#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
int t,n,a[2001],ans,maxn,bin[2001],lst[31];
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
        bin[y]=x;
}
inline bool check()
{
    for(int i=0;i<=30;++i)
        lst[i]=0;
    for(int i=1;i<=n;++i)
    {
        bin[i]=0;
        for(int j=0;j<=30;++j)
            if(a[i]>>j&1)
            {
                if(lst[j])
                    link(i,lst[j]);
                lst[j]=i;
            }
    }
    for(int i=2;i<=n;++i)
        if(anc(i)^anc(1))
            return 0;
    return 1;
}
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=maxn=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            if(!a[i])
            {
                a[i]=1;
                ++ans;
            }
            maxn=max(maxn,a[i]&-a[i]);
        }
        if(check())
        {
            cout<<ans<<'\n';
            for(int i=1;i<=n;++i)
                cout<<a[i]<<" ";
            cout<<'\n';
            continue;
        }
        ++ans;
        bool flag=0;
        for(int i=1;i<=n;++i)
        {
            ++a[i];
            if(check())
            {
                cout<<ans<<'\n';
                for(int i=1;i<=n;++i)
                    cout<<a[i]<<" ";
                cout<<'\n';
                flag=1;
                break;
            }
            a[i]-=2;
            if(check())
            {
                cout<<ans<<'\n';
                for(int i=1;i<=n;++i)
                    cout<<a[i]<<" ";
                cout<<'\n';
                flag=1;
                break;
            }
            ++a[i];
        }
        if(flag)
            continue;
        ++ans;
        for(int i=1;i<=n;++i)
            if((a[i]&-a[i])==maxn)
            {
                --a[i];
                break;
            }
        for(int i=1;i<=n;++i)
            if((a[i]&-a[i])==maxn)
            {
                ++a[i];
                break;
            }
        cout<<ans<<'\n';
        for(int i=1;i<=n;++i)
            cout<<a[i]<<" ";
        cout<<'\n';
    }
    return 0;
}