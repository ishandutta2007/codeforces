#include<bits/stdc++.h>
using namespace std;
const int N = 1.1e5;
int n,q;
namespace HASH
{
    const int mod = 1e9+7;
    const int bs = 29;
    const int iv = 758620695;
    int _w[N<<1],*w=_w+N;
    void init(int N)
    {
        w[0]=1;
        for(int i=1;i<N;++i)
        {
            w[+i]=1ll*w[i-1]*bs%mod;
            w[-i]=1ll*w[1-i]*iv%mod;
            assert(1ll*w[i]*w[-i]%mod==1);
        }
    }
    // hash
    struct str
    {
        int val,len;
        str(int _v=0,int _len=0):val(_v),len(_len) {}
        inline bool operator == (const str&rhs) const
        { return val==rhs.val&&len==rhs.len; }
        inline str operator + (const str&rhs) const // A+B = AB 
        { return str((val+1ll*rhs.val*w[len])%mod,len+rhs.len); }
        inline str operator - (const str&rhs) const // AB-B = A
        { return str(1ll*(val-rhs.val+mod)*w[-rhs.len]%mod,len-rhs.len); }
    };
}
using HASH::str;
#define seg 1,1,n
#define ls (o<<1)
#define rs (o<<1|1)
#define mid (l+r)/2
#define lson ls,l,mid
#define rson rs,mid+1,r
struct node
{
    bool wrong;
    str vl,vr; // vl left vr right
    node(int _v=0)
    {
        wrong=0;
        if(_v!=0)
            _v>0? vr=str(_v,1): vl=str(-_v,1);
    }
} tr[N<<3];
str gvalL(int o,int k) // prefix
{
    if(!k) return str();
    if(k==tr[o].vl.len) return tr[o].vl;
    if(k<=tr[ls].vl.len) return gvalL(ls,k);
    return tr[ls].vl+(gvalL(rs,k-tr[ls].vl.len+tr[ls].vr.len)-tr[ls].vr);
}
str gvalR(int o,int k) // suffix
{
    if(!k) return str();
    if(k==tr[o].vr.len) return tr[o].vr;
    if(k<=tr[rs].vr.len) return gvalR(rs,k);
    return tr[rs].vr+(gvalR(ls,k-tr[rs].vr.len+tr[rs].vl.len)-tr[rs].vl);
}
inline void pushup(int o)
{
    tr[o].wrong=tr[ls].wrong|tr[rs].wrong;
    if(tr[o].wrong) return ;
    tr[o].vl=tr[ls].vl, tr[o].vr=tr[rs].vr;
    if(tr[ls].vr.len<=tr[rs].vl.len)
    {
        if(tr[ls].vr==gvalL(rs,tr[ls].vr.len))
            tr[o].vl=tr[o].vl+(tr[rs].vl-tr[ls].vr);
        else tr[o].wrong|=1;
    }
    else
    {
        if(tr[rs].vl==gvalR(ls,tr[rs].vl.len))
            tr[o].vr=tr[o].vr+(tr[ls].vr-tr[rs].vl);
        else tr[o].wrong|=1;
    }
}
void build(int o=1,int l=1,int r=n,int val=0)
{
    if(l==r) return scanf("%d",&val),tr[o]=node(val),void();
    build(lson),build(rson),pushup(o);
}
void modify(int pos,int val,int o=1,int l=1,int r=n)
{
    if(l==r) return void(tr[o]=node(val));
    (pos<=mid)?modify(pos,val,lson): modify(pos,val,rson);
    return pushup(o);
}
int sta[50],top; str seq[50];
void getsta(int li,int ri,int o=1,int l=1,int r=n)
{
    if(li<=l&&r<=ri) return sta[++top]=o,void();
    if(li<=mid) getsta(li,ri,lson); 
    if(ri >mid) getsta(li,ri,rson);
}
str getval(int o,int k)
{
    if(!k) return str();
    if(k==seq[o].len) return seq[o];
    if(k<=tr[sta[o]].vr.len) return gvalR(sta[o],k);
    return tr[sta[o]].vr+(getval(o-1,k-tr[sta[o]].vr.len+tr[sta[o]].vl.len)-tr[sta[o]].vl);
}
bool query(int l,int r)
{
    top=0; getsta(l,r);
    for(int i=1;i<=top;++i)
    {
        if(tr[sta[i]].wrong) return 0;
        if(seq[i-1].len<tr[sta[i]].vl.len) return 0;
        if(tr[sta[i]].vl==getval(i-1,tr[sta[i]].vl.len))
            seq[i]=tr[sta[i]].vr+(seq[i-1]-tr[sta[i]].vl);
        else return 0;
    }
    return seq[top].len==0;
}
signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.in","r",stdin);
        // freopen("test.out","w",stdout);
    #endif
    scanf("%d%*d",&n); HASH::init(n); build();
    scanf("%d",&q); for(int t,x,y;q--;)
    {
        scanf("%d %d %d",&t,&x,&y);
        if(t==1) modify(x,y);
        else puts(query(x,y)?"Yes":"No");
    }
    return 0;
}