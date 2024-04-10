#include<bits/stdc++.h>
using namespace std;
#define inf 9223372036854775807ll
#define ll long long
struct point{
    ll x,y;
    point(int a=0,int b=0){
        x=a;
        y=b;
    }
};
point operator-(point a,point b){
    return point(a.x-b.x,a.y-b.y);
}
ll operator*(point a,point b){
    return a.x*b.y-a.y*b.x;
}
bool operator<(point a,point b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
typedef vector<point> vp;
vp tag[1200010];
point p[300010];
int _end[300010];
ll ask[300010];
void modify(int L,int R,int l,int r,int x){
    if(L<=l&&r<=R){
        tag[x].push_back(p[L]);
        return;
    }
    int mid=(l+r)>>1;
    if(L<=mid)modify(L,R,l,mid,x<<1);
    if(mid<R)modify(L,R,mid+1,r,x<<1|1);
}
void dfs(int l,int r,int x){
    vp&v=tag[x];
    if(!v.empty())sort(v.begin(),v.end());
    if(v.size()>2){
        int i,j;
        for(i=2,j=1;i<v.size();i++){
            while(j>0&&(v[j]-v[j-1])*(v[i]-v[j-1])>=0)j--;
            j++;
            v[j]=v[i];
        }
        while(v.size()>(j+1))v.pop_back();
    }
    if(l==r)return;
    int mid=(l+r)>>1;
    dfs(l,mid,x<<1);
    dfs(mid+1,r,x<<1|1);
}
ll ans;
ll calc(point p,ll v){
    return p.x*v+p.y;
}
ll solve(vp&vt,ll v){
    ll ans=-inf;
    int i,l,r,m1,m2;
    l=0;
    r=vt.size()-1;
    while(r-l>6){
        m1=(l*2+r)/3;
        m2=(l+r*2)/3;
        if(calc(vt[m1],v)<calc(vt[m2],v))
            l=m1;
        else
            r=m2;
    }
    for(i=l;i<=r;i++)ans=max(ans,calc(vt[i],v));
    return ans;
}
void query(int pos,ll v,int l,int r,int x){
    ans=max(ans,solve(tag[x],v));
    if(l==r)return;
    int mid=(l+r)>>1;
    if(pos<=mid)
        query(pos,v,l,mid,x<<1);
    else
        query(pos,v,mid+1,r,x<<1|1);
}
int main(){
    int n,i,op,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        _end[i]=-1;
        ask[i]=-inf;
        scanf("%d",&op);
        if(op==1){
            scanf("%I64d%I64d",&p[i].x,&p[i].y);
            _end[i]=n;
        }
        if(op==2){
            scanf("%d",&x);
            _end[x]=i-1;
        }
        if(op==3)scanf("%I64d",ask+i);
    }
    for(i=1;i<=n;i++){
        if(_end[i]!=-1)modify(i,_end[i],1,n,1);
    }
    dfs(1,n,1);
    for(i=1;i<=n;i++){
        if(ask[i]!=-inf){
            ans=-inf;
            query(i,ask[i],1,n,1);
            if(ans==-inf)
                puts("EMPTY SET");
            else
                printf("%I64d\n",ans);
        }
    }
}