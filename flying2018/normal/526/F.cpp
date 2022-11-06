#include<iostream>
#include<cstdio>
#include<cstring>
#define N 600010
using namespace std;
int num[N];
struct ST{
    int lg[N],al[N][19],ar[N][19];
    void init(int n)
    {
        lg[1]=0;
        for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
        for(int i=1;i<=n;i++) al[i][0]=ar[i][0]=num[i];
        for(int i=1;i<=18;i++)
            for(int j=1;j+(1<<i)-1<=n;j++) al[j][i]=min(al[j][i-1],al[j+(1<<(i-1))][i-1]),ar[j][i]=max(ar[j][i-1],ar[j+(1<<(i-1))][i-1]);
    }
    int get_min(int l,int r){int t=lg[r-l+1];return min(al[l][t],al[r-(1<<t)+1][t]);}
    int get_max(int l,int r){int t=lg[r-l+1];return max(ar[l][t],ar[r-(1<<t)+1][t]);}
}st;
struct seg_tree{
    int val[N<<2],tag[N<<2];
    void set_tag(int u,int v){val[u]+=v;tag[u]+=v;}
    void push_down(int u)
    {
        if(!tag[u]) return;
        set_tag(u<<1,tag[u]),set_tag(u<<1|1,tag[u]),tag[u]=0;
    }
    void insert(int u,int l,int r,int L,int R,int v)
    {
        if(L<=l && r<=R){set_tag(u,v);return;}
        push_down(u);
        int mid=(l+r)>>1;
        if(L<=mid) insert(u<<1,l,mid,L,R,v);
        if(R>mid) insert(u<<1|1,mid+1,r,L,R,v);
        val[u]=min(val[u<<1],val[u<<1|1]);
    }
    int answer(int u,int l,int r)
    {
        if(l==r) return l;
        push_down(u);
        int mid=(l+r)>>1;
        if(!val[u<<1]) return answer(u<<1,l,mid);
        else return answer(u<<1|1,mid+1,r);
    }
}t;
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}
int dep[N];
bool a_line(int l,int r){return st.get_max(l,r)-st.get_min(l,r)==r-l;}
int t1[N],tt1,t2[N],tt2;
int tn[N],tp;
int mn[N],id[N],lf[N],rf[N],typ[N],tot;
int build(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(;tt1 && num[i]<=num[t1[tt1]];tt1--) t.insert(1,1,n,t1[tt1-1]+1,t1[tt1],num[t1[tt1]]);
        for(;tt2 && num[i]>=num[t2[tt2]];tt2--) t.insert(1,1,n,t2[tt2-1]+1,t2[tt2],-num[t2[tt2]]);
        t.insert(1,1,n,t1[tt1]+1,i,-num[i]);
        t.insert(1,1,n,t2[tt2]+1,i,num[i]);
        t1[++tt1]=t2[++tt2]=i;
        id[i]=++tot;lf[tot]=rf[tot]=i;
        int p=t.answer(1,1,n),u=tot;
        while(tp && lf[tn[tp]]>=p)
        {
            if(typ[tn[tp]] && a_line(mn[tn[tp]],i)){rf[tn[tp]]=i;add(tn[tp],u);u=tn[tp--];continue;}
            if(a_line(lf[tn[tp]],i))
            {
                typ[++tot]=1;
                lf[tot]=lf[tn[tp]],rf[tot]=i;mn[tot]=lf[u];
                add(tot,tn[tp--]),add(tot,u);
            }
            else
            {
                add(++tot,u);
                do add(tot,tn[tp--]); while(tp && !a_line(lf[tn[tp]],i));
                lf[tot]=lf[tn[tp]],rf[tot]=i;
                add(tot,tn[tp--]);
            }
            u=tot;
        }
        tn[++tp]=u;
        t.insert(1,1,n,1,i,-1);
    }
    return tn[1];
}
long long ans;
void dfs(int u,int p)
{
    dep[u]=dep[p]+1;
    int deg=0;
    for(int i=head[u];i;i=nxt[i]) dfs(to[i],u),++deg;
    if(typ[u]) ans+=1ll*deg*(deg-1)/2;
    else ans++;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        num[x]=y;
    }
    st.init(n);
    int rt=build(n);
    dfs(rt,0);
    printf("%lld",ans);
    return 0;
}