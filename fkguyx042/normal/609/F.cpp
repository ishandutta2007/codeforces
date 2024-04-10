#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>

#define mk make_pair
#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)
#define fi first
#define se second

#define N 200005

using namespace std;
int i,j,m,n,p,k,x[N],b[N],P,B,ans[N],id[N*4];
long long t[N];
struct Tre{
   long long sum[N*4];
   void modify(int ll,int c,int l,int r,int t)
   {
        if (l==r) sum[t]+=c;
        else 
        {
            if (ll<=mid) modify(ll,c,l,mid,ls);
            else modify(ll,c,mid+1,r,rs);
            sum[t]=max(sum[ls],sum[rs]);
        }
   }
   int ask(int l,int r,int t)
   {
            if (l==r) 
            {
                 if (b[l]>P||sum[t]<P) return 0;
                 return id[t];
            }
            else 
            {
                 if (sum[ls]>=P) return ask(l,mid,ls);
                 else return ask(mid+1,r,rs);
            }
    }
 }tree;
void modify(int ll,int c,int l,int r,int t)
{
   if (l==r) id[t]=c;
   else 
   {
     if (ll<=mid) modify(ll,c,l,mid,ls);
     else modify(ll,c,mid+1,r,rs);
   }
}
multiset<pair<int,int> >st;
multiset<pair<int,int> >::iterator it;
int main()
{
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;++i) scanf("%d%I64d",&x[i],&t[i]),b[i]=x[i];
   sort(b+1,b+n+1); b[0]=n;
   for (i=1;i<=n;++i) x[i]=lower_bound(b+1,b+b[0]+1,x[i])-b;
   for (i=1;i<=n;++i) tree.modify(x[i],b[x[i]]+t[i],1,n,1),modify(x[i],i,1,n,1);
   for (;m--;)
   {
        scanf("%d%d",&P,&B);
        int  c=tree.ask(1,n,1);
        if (c)
        {
                  t[c]+=B; ans[c]++; tree.modify(x[c],B,1,n,1);
                  for (;;)
                  {
                    it=st.lower_bound(mk(b[x[c]],0));
                    if (it==st.end()) break;
                    if (it->fi>b[x[c]]+t[c]) break;
                    t[c]+=it->se; ans[c]++; tree.modify(x[c],it->se,1,n,1);
                    st.erase(it);
                  }
        }
        else st.insert(mk(P,B));
   }
   for (i=1;i<=n;++i) printf("%d %I64d\n",ans[i],t[i]);
}