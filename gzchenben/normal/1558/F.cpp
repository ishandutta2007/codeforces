#include<cstdio>
#include<algorithm>
using namespace std;
class Segment_Tree
{
    public:
    long long data[8000005],tag[8000005];
    void Update(int k)
    {
        data[k]=max(data[2*k],data[2*k+1]);
    }
    void Add(int k,long long val)
    {
        data[k]+=val;
        tag[k]+=val;
    }
    void Pushdown(int k)
    {
        if(!tag[k]) return;
        Add(2*k,tag[k]);
        Add(2*k+1,tag[k]);
        tag[k]=0;
    }
    void Build(int k,int l,int r)
    {
        tag[k]=0;
        data[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        Build(2*k,l,mid);
        Build(2*k+1,mid+1,r);
        Update(k);
    }
    void Modify(int k,int l,int r,int ql,int qr,long long val)
    {
        if(l>qr || r<ql) return;
        if(ql<=l && qr>=r) return Add(k,val);
        int mid=(l+r)/2;
        Pushdown(k);
        Modify(2*k,l,mid,ql,qr,val);
        Modify(2*k+1,mid+1,r,ql,qr,val);
        Update(k);
    }
    long long Query(int k,int l,int r,int ql,int qr)
    {
        if(l>qr || r<ql) return 0;
        if(ql<=l && qr>=r) return data[k];
        Pushdown(k);
        int mid=(l+r)/2;
        return max(Query(2*k,l,mid,ql,qr),Query(2*k+1,mid+1,r,ql,qr));
    }
}S;
int n,t,a[200005],pos[200005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        S.Build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pos[a[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
            S.Modify(1,1,n,i,i,n-i+(i%2));
        }
        long long Maxn=0;
        int Lst1=n;
        for(int i=n;i>=1;i--)
        {
            Lst1=min(Lst1,pos[i]-1);
            S.Modify(1,1,n,pos[i],pos[i],-1e7);
            S.Modify(1,1,n,1,n,-1);
            S.Modify(1,1,n,pos[i]+1,n,2);
            Maxn=max(Maxn,S.Query(1,1,n,Lst1+1,n));
        }
        printf("%lld\n",Maxn);
    }
}
// g(i) = |S| - i + pos - i + pos % 2