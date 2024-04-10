#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define int long long
int n,a[200001],len[200001],ans,sum;
struct element
{
    int val,len,cnt;
    element(int val_,int len_,int cnt_):
        val(val_),len(len_),cnt(cnt_){}
    bool operator <(const element &other) const
    {
        return val<other.val;
    }
};
priority_queue<element> q;
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
inline int calc(int x,int y)
{
    int v0=x/y,v1=v0+1,k1=x-v0*y,k0=y-k1;
    return v1*v1*k1+v0*v0*k0;
}
signed main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        len[i]=a[i]-a[i-1];
        sum+=len[i]*len[i];
        if(len[i]>1)
            q.emplace(calc(len[i],1)-calc(len[i],2),len[i],1);
    }
    sum-=read();
    while(sum>0)
    {
        element k=q.top();
        q.pop();
        if(k.len/k.cnt!=k.len/(k.cnt+1))
        {
            ++ans;
            sum-=k.val;
            ++k.cnt;
            int val=calc(k.len,k.cnt)-calc(k.len,k.cnt+1);
            if(val)
                q.emplace(val,k.len,k.cnt);
            continue;
        }
        int pos=k.len/(k.len/k.cnt);
        if((pos-k.cnt)*k.val>=sum)
        {
            ans+=(sum-1)/k.val+1;
            break;
        }
        ans+=pos-k.cnt;
        sum-=k.val*(pos-k.cnt);
        k.cnt=pos;
        int val=calc(k.len,k.cnt)-calc(k.len,k.cnt+1);
        if(val)
            q.emplace(val,k.len,k.cnt);
    }
    cout<<ans<<'\n';
    return 0;
}