#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int t,n,a,b,p[MAXN],dist[MAXN];
struct segtree
{
    int maxi[4*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void build(int k,int l,int r,int type)
    {
        if(l==r)
        {
            if(type==0) maxi[k]=p[l]+l;
            else maxi[k]=p[l]-l;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid,type); build(k*2+1,mid+1,r,type);
        pushup(k);
    }
    void update(int k,int l,int r,int pos,int v)
    {
        if(l==r) 
        {
            maxi[k]=v; return; 
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,v); else update(k*2+1,mid+1,r,pos,v);
        pushup(k);
    }
    //find first position in [x,y] with value>=v in O(log n)
    int find_pos(int k,int l,int r,int x,int y,int v)
    {
        if(maxi[k]<v) return INF;
        if(l>y||x>r) return INF;
        if(l==r) return l;
        int mid=(l+r)/2;
        int res=find_pos(k*2,l,mid,x,y,v);
        if(res!=INF) return res; else return find_pos(k*2+1,mid+1,r,x,y,v);
    }
}seg1,seg2;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&b);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        for(int i=1;i<=n;i++) dist[i]=INF;
        seg1.build(1,1,n,0); seg2.build(1,1,n,1);
        queue<int> que;
        dist[a]=0;
        que.push(a);
        seg1.update(1,1,n,a,-INF); seg2.update(1,1,n,a,-INF);
        while(que.size())
        {
            if(dist[b]!=INF) break;
            int v=que.front(); que.pop();
            //printf("v=%d dist=%d\n",v,dist[v]);
            //update to the left
            int l=max(1,v-p[v]),r=max(1,v-1);
            //printf("left l=%d r=%d\n",l,r);
            //must satisfy p[j]+j>=v
            int x=seg1.find_pos(1,1,n,l,r,v);
            while(x!=INF)
            {
                //printf("update left %d\n",x);
                dist[x]=dist[v]+1;
                que.push(x);
                seg1.update(1,1,n,x,-INF); seg2.update(1,1,n,x,-INF);
                x=seg1.find_pos(1,1,n,l,r,v);
            }
            //update to the right
            l=min(n,v+1); r=min(n,v+p[v]);
            //printf("right l=%d r=%d\n",l,r);
            //must satisfy p[j]-j>=-v
            x=seg2.find_pos(1,1,n,l,r,-v);
            while(x!=INF)
            {
                //printf("update right %d\n",x);
                dist[x]=dist[v]+1;
                que.push(x);
                seg1.update(1,1,n,x,-INF); seg2.update(1,1,n,x,-INF);
                x=seg2.find_pos(1,1,n,l,r,-v);
            }
        }
        printf("%d\n",dist[b]);
    }
    return 0;
}