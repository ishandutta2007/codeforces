//~
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const int maxn=2011;
int n;
struct segment
{
    int x,y,id;
    bool operator<(const segment &tmp)const
    {
        if(y==tmp.y)
            return x>tmp.x;
        return y<tmp.y;
    }
}a[maxn];
struct BIT
{
    int a[5011],aid[5011];
    void init()
    {
        memset(a,0,sizeof(a));
        memset(aid,-1,sizeof(aid));
    }
    void add(int id,int x,int tmp)
    {
        while(id<=5000)
        {
            if(x>a[id])
                a[id]=x,aid[id]=tmp;
            id+=id&(-id);
        }
    }
    pair<int,int> cal(int id)
    {
        int ans=0,ansid=-1;
        while(id>0)
        {
            if(a[id]>ans)
                ans=a[id],ansid=aid[id];
            id-=id&(-id);
        }
        return MP(ans,ansid);
    }
}bit;
vector<int>pt;
int b[maxn],c[maxn],pre[maxn];
vector<int>bv[maxn];
void dfs(int x)
{
    if(x==-1)
        return;
    cout<<a[x].id<<" ";
    for(int i=0;i<bv[x].size();i++)
        dfs(bv[x][i]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int r,c;
        cin>>r>>c;
        a[i].x=r-c,a[i].y=r+c;
        a[i].id=i;
    }
    int mn=a[1].x,mx=a[1].y;
    for(int i=1;i<=n;i++)
        pt.PB(a[i].x),pt.PB(a[i].y),mn=min(mn,a[i].x),mx=max(mx,a[i].y);
    a[n+1].x=mn,a[n+1].y=mx;
    sort(pt.begin(),pt.end());
    pt.erase(unique(pt.begin(),pt.end()),pt.end());
    for(int i=1;i<=n+1;i++)
    {
        a[i].x=lower_bound(pt.begin(),pt.end(),a[i].x)-pt.begin()+1;
        a[i].y=lower_bound(pt.begin(),pt.end(),a[i].y)-pt.begin()+1;
    }
    sort(a+1,a+n+2);
    for(int i=1;i<=n+1;i++)
    {
        pair<int,int>t;
        bit.init();
        for(int j=1;j<i;j++)
        {
            if(a[j].x>=a[i].x&&a[i].y>=a[j].y)
            {
                t=bit.cal(a[j].x);
                c[j]=t.FF+b[j];
                pre[j]=t.SS;
                bit.add(a[j].y,c[j],j);
            }
        }
        t=bit.cal(a[i].y);
        b[i]=t.FF+1;
        int pos=t.SS;
        while(pos!=-1)
        {
            bv[i].PB(pos);
            pos=pre[pos];
        }
    }
    cout<<b[n+1]-1<<endl;
    for(int i=0;i<bv[n+1].size();i++)
        dfs(bv[n+1][i]);
    cout<<endl;
    return 0;
}