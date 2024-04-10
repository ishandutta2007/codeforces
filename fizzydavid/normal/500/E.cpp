//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,q,p[200111],l[200111],r[200111],u[200111][22],sum[200111][22];
int binsearch(int x)
{
    int l=1,r=n,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(p[mid]<x)l=mid+1;else r=mid-1;
    }
    return l;
}
struct node
{
    int l,r,v;
    node *ln,*rn;
};
node* build(int l,int r)
{
    node* p=new node;
    p->l=l;p->r=r;p->v=0;
    if(l==r)p->ln=p->rn=NULL;
    else
    {
        p->ln=build(l,(l+r)/2);
        p->rn=build((l+r)/2+1,r);
    }
    return p;
}
void add(node *p,int x,int v)
{
    if(p->r<x||p->l>x)return;
    p->v=max(p->v,v);
    if(p->l==p->r)return;
    int mid=(p->l+p->r)/2;
    if(x<=mid)add(p->ln,x,v);
    if(mid<x)add(p->rn,x,v);
}
int query(node *p,int l,int r)
{
    if(p->r<l||p->l>r)return 0;
    if(l<=p->l&&p->r<=r)return p->v;
    int mid=(p->l+p->r)/2,ans=0;
    if(l<=mid)ans=max(ans,query(p->ln,l,r));
    if(mid<r)ans=max(ans,query(p->rn,l,r));
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    node *root=build(1,n);
    for(int i=1;i<=n;i++)cin>>p[i]>>l[i];
    for(int i=n;i>=1;i--)
    {
        r[i]=max(p[i]+l[i],query(root,i,binsearch(p[i]+l[i])-1));
        add(root,i,r[i]);
    }
    for(int i=1;i<=n;i++)u[i][0]=binsearch(r[i]),sum[i][0]=(u[i][0]>n?0:p[u[i][0]]-r[i]);
    for(int i=1;i<=20;i++)for(int j=1;j<=n;j++)
    {
        if(u[j][i-1]>n)u[j][i]=n+1,sum[j][i]=sum[j][i-1];
        else u[j][i]=u[u[j][i-1]][i-1],sum[j][i]=sum[j][i-1]+sum[u[j][i-1]][i-1];
    }
    cin>>q;int x,y;
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        int pos=x,ans=0;
        for(int tmp=20;tmp>=0;tmp--)
        {
            if(u[pos][tmp]<=y)
            {
                ans+=sum[pos][tmp];
                pos=u[pos][tmp];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}